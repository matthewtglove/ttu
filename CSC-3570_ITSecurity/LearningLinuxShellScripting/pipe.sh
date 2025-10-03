#!/usr/bin/env bash

files=`ls -1 | sort -r | head -3`
count=1

for file in $files; do
    echo "File $count: $file"
    ((count++))
done

exit 0