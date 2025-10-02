#!/usr/bin/env bash

count=0
endCount=$1

while [ $count -le $endCount ]; do
    echo "Count is: $count"
    ((count++))
done

echo "Loop Finished"

exit 0