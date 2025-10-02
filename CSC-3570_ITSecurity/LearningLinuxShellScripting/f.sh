#!/usr/bin/env bash

# (put this in /usr/local/bin/ as 'f')
# Shortcut command to create a new file with executable permissions (755)

RED="\033[31m"
GREEN="\033[32m"
CYAN="\033[36m"
RESET="\033[0m"

filename=$1

if [ -z "$filename" ]; then
    echo -e "${RED}Error: Missing parameter. Please provide a filename.${RESET}"
    exit 1
fi

touch "$filename"
chmod 755 "$filename"
echo -e "${GREEN}Created ${CYAN}'$filename'${GREEN} with executable permissions (755)!${RESET}"