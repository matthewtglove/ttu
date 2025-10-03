#!/usr/bin/env bash

count=1

while IFS='' read -r line ; do
    if [ $count -gt 3 ]; then
        break
    fi
    echo "Line $count: $line"
    ((count++))
done < "$1"

exit 0