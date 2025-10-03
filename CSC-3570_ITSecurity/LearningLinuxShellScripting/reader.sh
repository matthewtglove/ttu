#!/usr/bin/env bash

count=1

while IFS='' read -r line; do
    echo "Line $count: $line"
    ((count++))
done < "$1"

exit 0