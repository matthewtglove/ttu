#!/usr/bin/env bash

GetFiles() {
    echo "$(ls -1 | sort | head -10)"
}

ShowFiles() {
    local files=$1
    local count=1
    for file in $files; do
    echo "File $count: $file"
    ((count++))
    done
}

echo ""
ShowFiles "$(GetFiles)"
echo ""

exit 0