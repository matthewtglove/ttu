# 📄 CSC 4575 – Jupyter Notebook → Clean PDF Export Guide (VS Code)

# Step 1 – Ensure Notebook Reproducibility

Before exporting:

1. Click **Kernel → Restart & Run All**
2. Confirm:

   * All cells run without error
   * All output appears directly under the corresponding code cell
   * No tracebacks appear
3. Save the notebook

This ensures your PDF reflects a clean execution.

---

# Step 2 – Use a Light Theme (Important)

If you are using a dark theme in VS Code:

* Switch to a light theme before exporting

  * `View → Command Palette → Color Theme → Light+`

This prevents white text on dark background in your PDF.

---

# Step 3 – Export to PDF in VS Code

In the notebook:

1. Click the **three dots (…)** in the upper right.
2. Select **Export**
3. Choose **PDF**
4. Save the file.

If PDF export fails:

* Export as HTML
* Open HTML in browser
* Print → Save as PDF

---

# Step 4 – PDF Cleanliness Requirements

Your PDF must:

* Show all code cells and their outputs
* Show all Markdown answers
* Not contain blank execution outputs
* Not contain error tracebacks
* Not contain excessively long raw binary dumps

If your PDF includes massive raw output, clean it:

* Comment out unnecessary print statements
* Keep output readable and selective

---

# Step 5 – File Naming Convention

Submit files named:

```
CSC4575_Module4_LastName_FirstName.ipynb
CSC4575_Module4_LastName_FirstName.pdf
```

---

# ⚠️ Common Problems (You Can Preempt Them)

Add this warning block in the instructions:

```markdown
### Common Export Mistakes to Avoid

- Forgetting to run all cells before export
- Exporting while errors are present
- Using dark mode (makes unreadable PDF)
- Including excessive raw output
- Submitting only the .ipynb file
```
