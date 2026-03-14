#!/bin/bash

# =============================================================================
# CSC 4575: Cryptography & Network Security - Environment Setup Script
# Version: 1.0 (Spring 2026)
# Target OS: Ubuntu 24.04 LTS (x86_64 or ARM64)
# 
# Description:
# This script automates the installation of all tools required for CSC 4575.
# It installs system dependencies, compiles the LibOQS (Post-Quantum) library,
# sets up a Python virtual environment, and configures network permissions.
# =============================================================================

# Colors for output
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${BLUE}=============================================================${NC}"
echo -e "${BLUE}     CSC 4575: Crypto Workstation Setup Initiated           ${NC}"
echo -e "${BLUE}=============================================================${NC}"

# 1. System Updates & Core Dependencies
# -----------------------------------------------------------------------------
echo -e "${GREEN}[+] Updating system package lists...${NC}"
sudo apt-get update

echo -e "${GREEN}[+] Installing core build tools and network utilities...${NC}"
# build-essential: GCC, Make, etc.
# cmake: Required for building LibOQS
# libssl-dev: Required for Python cryptography libraries
# tcpdump/net-tools: Required for Network Sniffing/VPN Labs
sudo apt-get install -y \
    build-essential \
    cmake \
    git \
    libssl-dev \
    python3-dev \
    python3-pip \
    python3-venv \
    tcpdump \
    net-tools \
    iproute2 \
    nmap \
    openssh-server \
    curl \
    unzip

# 2. Setup Course Directory Structure
# -----------------------------------------------------------------------------
COURSE_DIR="$HOME/csc4575"

if [ ! -d "$COURSE_DIR" ]; then
    echo -e "${GREEN}[+] Creating course directory at ${COURSE_DIR}...${NC}"
    mkdir -p "$COURSE_DIR"
else
    echo -e "${BLUE}[!] Course directory already exists. Skipping creation.${NC}"
fi

# 3. Post-Quantum Cryptography (LibOQS) Installation
# -----------------------------------------------------------------------------
# We must compile liboqs from source to get the shared library required by Python.
echo -e "${GREEN}[+] Setting up Post-Quantum Cryptography (LibOQS)...${NC}"
echo -e "${BLUE}    This may take a few minutes. Please wait.${NC}"

cd "$COURSE_DIR"

if [ ! -d "liboqs" ]; then
    git clone --branch main --single-branch https://github.com/open-quantum-safe/liboqs.git
    cd liboqs
    
    # Create build directory
    mkdir -p build && cd build
    
    # Configure CMake (Enable Shared Libs for Python binding)
    cmake -DBUILD_SHARED_LIBS=ON ..
    
    # Compile
    make -j$(nproc)
    
    # Install system-wide
    sudo make install
    
    # Update shared library cache
    sudo ldconfig
    
    echo -e "${GREEN}[+] LibOQS installed successfully.${NC}"
else
    echo -e "${BLUE}[!] LibOQS folder found. Skipping compilation.${NC}"
fi

# 4. Python Environment Setup
# -----------------------------------------------------------------------------
cd "$COURSE_DIR"
echo -e "${GREEN}[+] Setting up Python Virtual Environment...${NC}"

if [ ! -d "venv" ]; then
    python3 -m venv venv
    echo -e "${GREEN}[+] Virtual environment created.${NC}"
fi

# Activate environment to install packages
source venv/bin/activate

echo -e "${GREEN}[+] Installing Python Cryptography Libraries...${NC}"
# Upgrade pip first
pip install --upgrade pip

# Install Course Requirements
# cryptography: Standard AES/RSA
# pycryptodome: Additional primitives
# scapy: Network packet manipulation (VPN Lab)
# liboqs-python: Wrapper for the PQC C-library we just built
pip install \
    cryptography \
    pycryptodome \
    scapy \
    jupyter \
    pandas \
    matplotlib

# Install liboqs-python wrapper (Must match the C library version)
# We install directly from the OQS python repo to ensure compatibility
echo -e "${GREEN}[+] Installing LibOQS Python Bindings...${NC}"
if pip show liboqs > /dev/null; then
     echo -e "${BLUE}[!] liboqs-python already installed.${NC}"
else
     # Clone and install the python wrapper
     cd "$COURSE_DIR"
     if [ ! -d "liboqs-python" ]; then
         git clone --branch main --single-branch https://github.com/open-quantum-safe/liboqs-python.git
     fi
     cd liboqs-python
     pip install .
fi

# 5. Network Permission Configuration (VPN/Sniffing Labs)
# -----------------------------------------------------------------------------
echo -e "${GREEN}[+] Configuring Network Capabilities (VPN/Wireshark Labs)...${NC}"
# This allows python and tcpdump to capture packets without being 'root' 
# (Safer for students)

# Find the path of the tcpdump binary
TCPDUMP_PATH=$(which tcpdump)
sudo setcap cap_net_raw,cap_net_admin=eip "$TCPDUMP_PATH"

echo -e "${BLUE}    Note: For raw socket Python scripts (VPN Lab), you may still need to run via 'sudo'.${NC}"

# 6. VS Code / Remote Access Prep
# -----------------------------------------------------------------------------
echo -e "${GREEN}[+] Verifying SSH Service...${NC}"
sudo systemctl enable ssh
sudo systemctl start ssh

# Get current IP
CURRENT_IP=$(hostname -I | cut -d' ' -f1)

# 7. Final Verification & Output
# -----------------------------------------------------------------------------
echo -e "${BLUE}=============================================================${NC}"
echo -e "${GREEN}     SETUP COMPLETE!                                         ${NC}"
echo -e "${BLUE}=============================================================${NC}"
echo -e "Your environment is ready."
echo -e ""
echo -e "To start working:"
echo -e "  1. Open VS Code on your host machine."
echo -e "  2. Install the 'Remote - SSH' extension."
echo -e "  3. Connect to: $USER@$CURRENT_IP"
echo -e ""
echo -e "To activate your python environment in the terminal:"
echo -e "  cd ~/csc4575"
echo -e "  source venv/bin/activate"
echo -e ""
echo -e "Post-Quantum Verify:"
echo -e "  Run 'python3 -c \"import oqs; print(oqs.oqs_version())\"' inside the venv."
echo -e "${BLUE}=============================================================${NC}"