#!/bin/bash

if [ $# > 1 ]; then
    echo "Invalid number of args. Expected 0 or 1."
    exit 1
fi

inputFile=""
if [ $# == 1 ]; then
    if [ ! -f $1 ]; then
        echo "File $1 does not exist"
        exit 1
    fi
    inputFile="$1"
fi
if [ $# == 0 ]; then
    inputFile="phonebook.dat"
fi

HI='\033[0;32m'
NORMAL='\033[0m'

echo "${HI}1. Starts or Ends with Jose$NORMAL"
# TODO: Check to use input file or default phonebook.dat
grep -E --color=always '^John' phonebook.dat

echo "${HI}2. Contains at least 27 upper or lower-case alphebetic characters$NORMAL"
echo "${HI}3. Contains more than 18 characters$NORMAL"
echo "${HI}4. Contains exactly 10 characters$NORMAL"
echo "${HI}5. Contains a sequence between 6 and 8 upper or lower-case alphebetic characters$NORMAL"
echo "${HI}6. Contains a local phone number (123-4567)$NORMAL"
echo "${HI}7. Contains a valid URL on a line by itself$NORMAL"
