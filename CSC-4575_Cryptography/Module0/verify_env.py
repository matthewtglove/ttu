#!/usr/bin/env python3
import sys
import shutil
import platform
import subprocess
import importlib.util

# =============================================================================
# CSC 4575: Lab 0 Verification Script
# =============================================================================

# ANSI Color Codes for Terminal Output
GREEN = "\033[92m"
RED = "\033[91m"
CYAN = "\033[96m"
YELLOW = "\033[93m"
RESET = "\033[0m"

def print_header():
    print(f"{CYAN}" + "="*60)
    print(f"   CSC 4575: Environment Verification Tool")
    print(f"   Running on: {platform.node()} ({platform.system()} {platform.release()})")
    print(f"   Python Ver: {sys.version.split()[0]}")
    print("="*60 + f"{RESET}\n")

def check_binary(name):
    """Checks if a Linux command line tool exists."""
    path = shutil.which(name)
    status = f"{GREEN}[INSTALLED]{RESET}" if path else f"{RED}[MISSING]{RESET}"
    print(f" {status} System Tool: {name:<15} Path: {path or 'Not Found'}")
    return 1 if path else 0

def check_python_package(package_name, import_name=None):
    """Checks if a Python library can be imported."""
    if import_name is None:
        import_name = package_name
    
    found = False
    try:
        # Try actual import to catch compilation errors (like missing .so files)
        module = __import__(import_name)
        found = True
        version = getattr(module, '__version__', 'Unknown')
    except ImportError:
        version = "Not Found"
    except Exception as e:
        version = f"Error: {str(e)}"

    status = f"{GREEN}[INSTALLED]{RESET}" if found else f"{RED}[MISSING]{RESET}"
    print(f" {status} Python Lib:  {package_name:<15} Ver: {version}")
    return 1 if found else 0

def check_liboqs():
    """Specific check for Post-Quantum Library (oqs)."""
    print(f"\n{YELLOW}--- Checking Post-Quantum Crypto (LibOQS) ---{RESET}")
    try:
        import oqs
        # Verify we can actually access the native library functions
        enabled_sigs = oqs.get_enabled_sig_mechanisms()
        count = len(enabled_sigs)
        print(f" {GREEN}[SUCCESS]{RESET}   LibOQS is compiled and linked.")
        print(f"            Available Quantum-Safe Algorithms: {count}")
        return True
    except ImportError:
        print(f" {RED}[FAILURE]{RESET}   Could not import 'oqs'.")
        print(f"            Did you run setup_vm.sh? Is the venv active?")
        return False
    except Exception as e:
        print(f" {RED}[FAILURE]{RESET}   LibOQS error: {e}")
        return False

def main():
    print_header()
    
    score = 0
    total_checks = 0

    print(f"{YELLOW}--- Checking System Binaries ---{RESET}")
    # Binaries installed by apt-get in setup_vm.sh
    binaries = ["git", "cmake", "gcc", "openssl", "tcpdump", "nmap"]
    for bin_name in binaries:
        score += check_binary(bin_name)
        total_checks += 1

    print(f"\n{YELLOW}--- Checking Python Environment ---{RESET}")
    # Python packages installed by pip in setup_vm.sh
    # Format: (pip package name, import name)
    py_packages = [
        ("cryptography", "cryptography"),
        ("pycryptodome", "Crypto"),
        ("scapy", "scapy"),
        ("pandas", "pandas"),
        ("jupyter", "jupyter_core")
    ]
    
    for pkg, imp in py_packages:
        score += check_python_package(pkg, imp)
        total_checks += 1

    # Special check for Post-Quantum
    pqc_status = check_liboqs()
    if pqc_status: 
        score += 1
    total_checks += 1

    print(f"\n{CYAN}" + "="*60)
    print(f"SUMMARY: {score}/{total_checks} Checks Passed")
    
    if score == total_checks:
        print(f"{GREEN}STATUS: READY FOR LABS{RESET}")
        print("Please take a screenshot of this window for your Lab 0 submission.")
    else:
        print(f"{RED}STATUS: INCOMPLETE ENVIRONMENT{RESET}")
        print("Please re-run ./setup_vm.sh or check error messages above.")
    print("="*60 + f"{RESET}")

if __name__ == "__main__":
    main()