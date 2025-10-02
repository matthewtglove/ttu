#!/usr/bin/env bash

# (put this in /usr/local/bin/ as 'f')
# Shortcut command to create a new file with executable permissions (755)

filename=$1

if [ -z "$filename" ]; then
    echo -e "Error: Missing parameter. Please provide a filename."
    exit 1
fi

touch "$filename"
chmod 755 "$filename"
echo -e "Created '$filename' with executable permissions (755)!"