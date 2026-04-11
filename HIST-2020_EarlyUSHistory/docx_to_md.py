#!/usr/bin/env python3
"""
docx_to_md.py — Convert .doc/.docx outline files to Markdown.

Usage:
    python docx_to_md.py input.docx
    python docx_to_md.py input1.docx input2.docx input3.docx
    python docx_to_md.py "Early US History Outlines (Source)"
    python docx_to_md.py "Early US History Outlines (Source)" -o "Early US History Outlines"

Features:
  - Red text (FF0000) → ==highlighted==
  - Bold → **bold**
  - Italic → *italic*
  - Bold+Italic → ***bold italic***
  - Roman numeral headings (I., II., III. ...) → ## Headers
  - Numbered items (1., 2., 3. ...) → top-level bullets
  - Sub-items (indented via tabs, `-`, or list style) → nested bullets
  - Skips preamble lines (title, "Key Terms", blank lines)
  - Trims extra whitespace
"""

import sys
import os
import re
import argparse
import subprocess
import tempfile
import shutil
import xml.etree.ElementTree as ET

# ── XML namespaces ────────────────────────────────────────────────────────────
NS = {
    'w':  'http://schemas.openxmlformats.org/wordprocessingml/2006/main',
    'r':  'http://schemas.openxmlformats.org/officeDocument/2006/relationships',
}

def ns(tag):
    """Expand a w:tag shorthand."""
    prefix, local = tag.split(':')
    return f'{{{NS[prefix]}}}{local}'


# ── Helpers ───────────────────────────────────────────────────────────────────

def unescape_xml_entities(text):
    """Convert common XML character entities to Unicode."""
    replacements = {
        '&#x2019;': '\u2019',  # right single quote / apostrophe
        '&#x2018;': '\u2018',  # left single quote
        '&#x201C;': '\u201c',  # left double quote
        '&#x201D;': '\u201d',  # right double quote
        '&#x2014;': '\u2014',  # em dash
        '&#x2013;': '\u2013',  # en dash
        '&#x00A0;': '\u00a0',  # non-breaking space
        '&amp;':    '&',
        '&lt;':     '<',
        '&gt;':     '>',
        '&quot;':   '"',
        '&apos;':   "'",
    }
    for entity, char in replacements.items():
        text = text.replace(entity, char)
    return text


def is_roman_numeral_heading(text):
    """Return True if the line starts with a Roman numeral like 'I.', 'II.', etc."""
    return bool(re.match(r'^(I{1,3}|IV|V?I{0,3}|IX|X{0,3})\.\s', text.strip()))


def is_numbered_item(text):
    """Return True if line starts with a number like '1.', '2.', etc."""
    return bool(re.match(r'^\d+\.\s', text.strip()))


def strip_leading_marker(text):
    """Remove leading numbered list marker (e.g. '1. ') or dash (e.g. '- ') from text."""
    text = re.sub(r'^\d+\.\s+', '', text)
    text = re.sub(r'^[-–]\s*', '', text)
    return text


def strip_emphasis_markers(text):
    """Remove Markdown bold/italic markers while keeping content intact."""
    return re.sub(r'\*{1,3}(.*?)\*{1,3}', r'\1', text)


def title_from_first_item(text):
    """Convert a numbered title item into plain heading text."""
    clean = strip_emphasis_markers(text).strip()
    clean = re.sub(r'^\d+\.\s*', '', clean)
    return clean.strip()


def strip_embedded_outline_number(text):
    """Remove duplicated leading numbering embedded in converted item text."""
    clean = text.strip()
    clean = re.sub(r'^\*{1,3}\s*\d+\.\s*\*{1,3}\s*', '', clean)
    clean = re.sub(r'^(\*{1,3})\s*\d+\.\s*', r'\1', clean)
    clean = re.sub(r'^\d+\.\s*', '', clean)
    return clean.strip()


def count_leading_tabs(para_elem):
    """
    Count <w:tab/> elements that appear before any text content in the paragraph.
    These represent indentation. Tabs after text are ignored.
    """
    leading = 0
    found_text = False
    for child in para_elem.iter():
        if child.tag == ns('w:t') and (child.text or '').strip():
            found_text = True
            break
        if child.tag == ns('w:tab') and not found_text:
            leading += 1
    return leading


# ── Run-level parsing ─────────────────────────────────────────────────────────

def parse_runs(para_elem):
    """
    Parse all <w:r> runs in a paragraph and return a list of
    (text, bold, italic, red) tuples.
    """
    runs = []
    for r in para_elem.iter(ns('w:r')):
        rpr = r.find(ns('w:rPr'))
        bold   = rpr is not None and (rpr.find(ns('w:b'))  is not None)
        italic = rpr is not None and (rpr.find(ns('w:i'))  is not None)
        color  = ''
        if rpr is not None:
            color_elem = rpr.find(ns('w:color'))
            if color_elem is not None:
                color = color_elem.get(ns('w:val'), '')
        red = color.upper() == 'FF0000'

        # Collect text and tab characters from this run
        text_parts = []
        for child in r:
            if child.tag == ns('w:t'):
                text_parts.append(child.text or '')
            # w:tab produces a tab character; we track these separately
            # (they are counted at the paragraph level)

        text = ''.join(text_parts)
        if text:
            runs.append((text, bold, italic, red))

    return runs


def format_run(text, bold, italic, red):
    """Apply Markdown formatting to a single run's text."""
    stripped = text.strip()
    if not stripped:
        return text
    before = text[: len(text) - len(text.lstrip())]
    after  = text[len(text.rstrip()):]
    inner  = stripped

    if red:
        # Highlight wraps the text; bold/italic applied outside at sentence level
        # (so italic context doesn't nest inside ==highlight==)
        if bold:
            inner = f'**=={inner}==**'
        else:
            inner = f'=={inner}=='
        return f'{before}{inner}{after}'
    else:
        if bold and italic:
            inner = f'***{inner}***'
        elif bold:
            inner = f'**{inner}**'
        elif italic:
            inner = f'*{inner}*'
        return f'{before}{inner}{after}'


def runs_to_markdown(runs):
    """Convert a list of (text, bold, italic, red) run tuples to a Markdown string."""
    if not runs:
        return ''

    # Check if all runs share italic (so we can wrap the whole line)
    all_italic = all(italic for _, _, italic, _ in runs)
    # If all italic, strip italic from individual runs and wrap whole result
    if all_italic:
        # Render without per-run italic markers, then wrap
        parts = []
        for text, bold, italic, red in runs:
            parts.append(format_run(text, bold, False, red))
        result = ''.join(parts)
        result = re.sub(r'  +', ' ', result).strip()
        if result:
            return f'*{result}*'
        return result

    parts = []
    for text, bold, italic, red in runs:
        parts.append(format_run(text, bold, italic, red))
    result = ''.join(parts)
    # Collapse multiple internal spaces (but not newlines)
    result = re.sub(r'  +', ' ', result)
    return result.strip()


# ── Paragraph-level classification ───────────────────────────────────────────

def classify_para(para_xml_str, para_elem):
    """
    Return a dict describing this paragraph:
        type:   'heading' | 'item' | 'subitem' | 'subsubitem' | 'skip'
        depth:  int (for items/subitems)
        text:   str (raw markdown text, no leading markers)
        raw:    str (original text before stripping marker)
    """
    # Count leading tabs (indentation before text content)
    tab_count = count_leading_tabs(para_elem)
    # Also check w:ind start value as an indentation hint
    ind_match = re.search(r'w:start="(\d+)"', para_xml_str)
    if ind_match:
        start = int(ind_match.group(1))
        tab_count = max(tab_count, start // 720)
    depth = tab_count

    # Also check for w:numPr (actual list item)
    is_list_item = '<w:numPr>' in para_xml_str

    runs = parse_runs(para_elem)
    if not runs:
        return {'type': 'skip', 'depth': 0, 'text': '', 'raw': ''}

    md_text = runs_to_markdown(runs)
    if not md_text:
        return {'type': 'skip', 'depth': 0, 'text': '', 'raw': ''}

    raw = md_text

    # Check for Roman numeral section heading (depth 0, bold)
    plain_text = re.sub(r'[*=]+', '', md_text).strip()
    if is_roman_numeral_heading(plain_text):
        # For headings: strip the Roman numeral prefix, keep ==highlights== but drop **bold** markers
        # (the ## syntax itself conveys heading importance)
        md_clean = re.sub(r'^(I{1,3}|IV|V?I{0,3}|IX|X{0,3})\.\s+', '', md_text.strip())
        # Remove bold (**) and italic (*) markers, but preserve ==highlights==
        md_clean = re.sub(r'\*{1,3}(.*?)\*{1,3}', r'\1', md_clean)
        md_clean = md_clean.strip()
        return {'type': 'heading', 'depth': 0, 'text': md_clean, 'raw': raw}

    # Numbered items (1., 2., ...) at shallow depth → top-level bullets
    if is_numbered_item(plain_text):
        clean_md = re.sub(r'^\d+\.\s+', '', md_text.strip())
        return {'type': 'item', 'depth': 1, 'text': clean_md, 'raw': raw}

    # Dash-prefixed items
    plain_dash = re.sub(r'[*=]+', '', md_text).strip()
    if plain_dash.startswith('-') or plain_dash.startswith('–'):
        # Determine sub-depth
        if depth >= 3:
            item_depth = 3
        elif depth >= 2 or is_list_item:
            item_depth = 2
        else:
            item_depth = 2

        # Distinguish bullet-marker dashes from content dashes:
        # "-Word" (no space after dash) → strip the dash (it's just a visual bullet)
        # "-   Word" (spaces after dash) → keep as "- Word" (it's meaningful content)
        # Check raw run text of first run
        first_run_text = runs[0][0] if runs else ''
        has_space_after_dash = bool(re.match(r'^[-–]\s+', first_run_text))

        if has_space_after_dash:
            # Keep dash as content: normalize to "- text"
            # Strip from runs at run level for clean formatting
            stripped_runs = list(runs)
            ft, fb, fi, fr = stripped_runs[0]
            ft = re.sub(r'^[-–]\s+', '', ft)
            stripped_runs[0] = (ft, fb, fi, fr)
            clean_md = '- ' + runs_to_markdown(stripped_runs)
        else:
            # Strip the dash — it was just a visual bullet marker
            stripped_runs = list(runs)
            ft, fb, fi, fr = stripped_runs[0]
            ft = re.sub(r'^[-–]', '', ft)
            stripped_runs[0] = (ft, fb, fi, fr)
            clean_md = runs_to_markdown(stripped_runs)

        return {'type': 'item', 'depth': item_depth, 'text': clean_md, 'raw': raw}

    if plain_text.startswith('+'):
        # Keep the + prefix — it's meaningful content
        return {'type': 'item', 'depth': depth if depth >= 2 else 2, 'text': md_text.strip(), 'raw': raw}

    # Actual list items (w:numPr)
    if is_list_item:
        return {'type': 'item', 'depth': 1, 'text': md_text, 'raw': raw}

    # Indented text → sub-items based on tab depth
    if depth >= 3:
        return {'type': 'item', 'depth': 3, 'text': md_text, 'raw': raw}
    if depth >= 2:
        return {'type': 'item', 'depth': 2, 'text': md_text, 'raw': raw}
    if depth >= 1:
        return {'type': 'item', 'depth': 1, 'text': md_text, 'raw': raw}

    # Default: treat as a heading if bold (section-level)
    rpr_all_bold = all(bold for txt, bold, italic, red in runs)
    if rpr_all_bold and runs:
        return {'type': 'heading', 'depth': 0, 'text': md_text, 'raw': raw}

    return {'type': 'item', 'depth': 0, 'text': md_text, 'raw': raw}


# ── Preamble / skip detection ─────────────────────────────────────────────────

SKIP_PATTERNS = [
    r'key\s+terms',            # "Key Terms are colored red"
    r'^history\s*\d+',          # Course headers like "History 2010"
    r'^part\s+(?:[ivx0-9]+|one|two|three|four|five)\b',  # Section preambles like "Part III" or "Part One"
]

def is_preamble(text):
    """Return True if this line should be skipped (title, legend, etc.)."""
    t = re.sub(r'[*=]+', '', text).strip().lower()
    for pattern in SKIP_PATTERNS:
        if re.search(pattern, t, re.IGNORECASE):
            return True
    return False


# ── Main conversion ───────────────────────────────────────────────────────────

def convert_docx_to_md(docx_path):
    """Parse the docx and return a Markdown string."""
    import zipfile

    with zipfile.ZipFile(docx_path) as z:
        doc_xml = z.read('word/document.xml').decode('utf-8')

    # Parse XML
    root = ET.fromstring(doc_xml)
    body = root.find(ns('w:body'))
    if body is None:
        raise ValueError("Could not find <w:body> in document.xml")

    paragraphs = body.findall(ns('w:p'))

    lines = []
    for para in paragraphs:
        # Get raw XML string for this paragraph for tab-counting, etc.
        para_xml_str = ET.tostring(para, encoding='unicode')

        info = classify_para(para_xml_str, para)
        if info['type'] == 'skip':
            continue

        text = unescape_xml_entities(info['text'])
        text = text.strip()
        if not text:
            continue

        if is_preamble(text):
            continue

        lines.append((info['type'], info['depth'], text))

    # Promote a leading numbered title item to a heading.
    if lines and lines[0][0] == 'item' and lines[0][1] <= 1:
        first_title = title_from_first_item(strip_embedded_outline_number(lines[0][2]))
        if first_title:
            lines[0] = ('heading', 0, first_title)

    # Normalize list depth jumps so generated indentation is stable.
    # Example: if an item jumps from depth 1 to depth 3 without an
    # intermediate depth-2 parent, reduce it to depth 2.
    normalized_lines = []
    prev_item_depth = 1
    for typ, depth, text in lines:
        if typ == 'heading':
            normalized_lines.append((typ, 0, text))
            prev_item_depth = 1
            continue

        depth = max(1, depth)
        if depth > prev_item_depth + 1:
            depth = prev_item_depth + 1
        normalized_lines.append((typ, depth, text))
        prev_item_depth = depth

    lines = normalized_lines

    # ── Render to Markdown ────────────────────────────────────────────────────
    md_lines = []

    # Track numbering per heading section for top-level items
    section_counter = 0

    for typ, depth, text in lines:
        if typ == 'heading':
            if md_lines:
                md_lines.append('')
            md_lines.append(f'## {text}')
            md_lines.append('')
            section_counter = 0   # reset numbered list for each new section
        elif typ == 'item':
            if depth <= 1:
                # Top-level items under a heading use numbered list
                section_counter += 1
                md_lines.append(f'{section_counter}. {strip_embedded_outline_number(text)}')
            else:
                # Sub-items always use a single tab to keep outline indentation consistent.
                indent = '\t'
                md_lines.append(f'{indent}- {strip_embedded_outline_number(text)}')

    # Clean up: remove duplicate blank lines, strip trailing whitespace
    result_lines = []
    prev_blank = False
    for line in md_lines:
        is_blank = line.strip() == ''
        if is_blank and prev_blank:
            continue
        result_lines.append(line.rstrip())
        prev_blank = is_blank

    # Remove leading/trailing blank lines
    while result_lines and result_lines[0].strip() == '':
        result_lines.pop(0)
    while result_lines and result_lines[-1].strip() == '':
        result_lines.pop()

    return '\n'.join(result_lines) + '\n'


# ── .doc → .docx conversion ───────────────────────────────────────────────────

def resolve_soffice_command():
    """Return a working LibreOffice command as a list, or None if unavailable."""
    candidates = []

    env_soffice = os.environ.get('SOFFICE_BIN')
    if env_soffice:
        candidates.append([env_soffice])

    # Common macOS install path for LibreOffice.
    candidates.append(['/Applications/LibreOffice.app/Contents/MacOS/soffice'])

    # PATH-based commands (Linux/macOS with package-managed installs).
    path_soffice = shutil.which('soffice')
    if path_soffice:
        candidates.append([path_soffice])

    path_libreoffice = shutil.which('libreoffice')
    if path_libreoffice:
        candidates.append([path_libreoffice])

    for cmd in candidates:
        exe = cmd[0]
        if not os.path.exists(exe) and os.path.sep in exe:
            continue
        try:
            probe = subprocess.run(
                cmd + ['--version'],
                capture_output=True,
                text=True
            )
            if probe.returncode == 0:
                return cmd
        except OSError:
            continue

    return None


def doc_to_docx(doc_path):
    """Convert a .doc file to .docx using LibreOffice, return path to .docx."""
    soffice_cmd = resolve_soffice_command()
    if not soffice_cmd:
        raise RuntimeError(
            'LibreOffice is required to convert .doc files, but no soffice binary was found. '
            'Install LibreOffice and ensure `soffice` is on PATH, or set SOFFICE_BIN '
            'to the full binary path (e.g., /Applications/LibreOffice.app/Contents/MacOS/soffice).'
        )

    tmp_dir = tempfile.mkdtemp()
    try:
        result = subprocess.run(
            soffice_cmd + ['--headless', '--convert-to', 'docx',
             '--outdir', tmp_dir, doc_path],
            capture_output=True, text=True
        )
        if result.returncode != 0:
            raise RuntimeError(f"LibreOffice conversion failed:\n{result.stderr}")
        # Find the output file
        base = os.path.splitext(os.path.basename(doc_path))[0]
        out_path = os.path.join(tmp_dir, base + '.docx')
        if not os.path.exists(out_path):
            # Search for any .docx in tmp_dir
            found = [f for f in os.listdir(tmp_dir) if f.endswith('.docx')]
            if not found:
                raise FileNotFoundError(f"No .docx produced in {tmp_dir}. stdout: {result.stdout}")
            out_path = os.path.join(tmp_dir, found[0])
        return out_path, tmp_dir
    except Exception:
        shutil.rmtree(tmp_dir, ignore_errors=True)
        raise


# ── Entry point ───────────────────────────────────────────────────────────────

DEFAULT_OUTPUT_DIR = 'Early US History Outlines'


def collect_input_files(input_paths):
    """Return a de-duplicated list of .doc/.docx files from file and directory inputs."""
    supported_exts = {'.doc', '.docx'}
    discovered = []

    for raw_path in input_paths:
        path = os.path.abspath(raw_path)
        if not os.path.exists(path):
            raise FileNotFoundError(f"file or directory not found: {raw_path}")

        if os.path.isfile(path):
            ext = os.path.splitext(path)[1].lower()
            if ext not in supported_exts:
                raise ValueError(f"unsupported file type '{ext}' for {raw_path}. Use .doc or .docx")
            discovered.append(path)
            continue

        # Directory input: gather supported files recursively so a whole source
        # folder can be converted in one command.
        for root_dir, _, file_names in os.walk(path):
            for file_name in sorted(file_names):
                ext = os.path.splitext(file_name)[1].lower()
                if ext in supported_exts:
                    discovered.append(os.path.join(root_dir, file_name))

    # Preserve order while removing duplicates.
    deduped = []
    seen = set()
    for path in discovered:
        if path in seen:
            continue
        deduped.append(path)
        seen.add(path)
    return deduped


def build_output_path(input_path, outdir):
    """Build output markdown path in the target output directory."""
    base_name = os.path.splitext(os.path.basename(input_path))[0]
    return os.path.join(outdir, f'{base_name}.md')


def main():
    parser = argparse.ArgumentParser(
        description='Convert one or more .doc/.docx files to Markdown.',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog='Examples:\n'
               '  python docx_to_md.py file1.docx file2.docx\n'
               '  python docx_to_md.py "Early US History Outlines (Source)"\n'
               '  python docx_to_md.py "Early US History Outlines (Source)" -o "Early US History Outlines"'
    )
    parser.add_argument(
        'inputs',
        nargs='+',
        help='One or more .doc/.docx files or directories containing them.'
    )
    parser.add_argument(
        '-o', '--outdir',
        default=DEFAULT_OUTPUT_DIR,
        help='Directory where .md files are written (default: %(default)s).'
    )
    args = parser.parse_args()

    try:
        input_files = collect_input_files(args.inputs)
    except Exception as exc:
        print(f'Error: {exc}', file=sys.stderr)
        sys.exit(1)

    if not input_files:
        print('Error: no .doc or .docx files found in the provided inputs.', file=sys.stderr)
        sys.exit(1)

    outdir = os.path.abspath(args.outdir)
    os.makedirs(outdir, exist_ok=True)

    converted = 0
    failed = 0

    for input_path in input_files:
        tmp_dir = None
        try:
            ext = os.path.splitext(input_path)[1].lower()
            if ext == '.doc':
                print(f'Converting {input_path} -> .docx via LibreOffice...', file=sys.stderr)
                docx_path, tmp_dir = doc_to_docx(input_path)
            else:
                docx_path = input_path

            md = convert_docx_to_md(docx_path)
            out_path = build_output_path(input_path, outdir)

            with open(out_path, 'w', encoding='utf-8') as f:
                f.write(md)

            converted += 1
            print(f'✓ Written to {out_path}', file=sys.stderr)

        except Exception as exc:
            failed += 1
            print(f'✗ Failed: {input_path}', file=sys.stderr)
            print(f'  {exc}', file=sys.stderr)

        finally:
            if tmp_dir:
                shutil.rmtree(tmp_dir, ignore_errors=True)

    print(f'Done: converted {converted} file(s), failed {failed}.', file=sys.stderr)
    if failed:
        sys.exit(1)


if __name__ == '__main__':
    main()
