#!/usr/bin/env bash

count=0

while [ $count -le 10 ]; do
    echo "Count is: $count"
    ((count++))
done

echo -e "\nFinished counting to 10!\n"

exit 0