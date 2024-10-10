#!/bin/bash

if [ $# -gt 1 ]; then
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

HI="\033[0;32m"
NORMAL="\033[0m"

echo -e "${HI}1. Starts or Ends with Jose$NORMAL"
grep -E --color=always '^Jose|Jose$' $inputFile

echo -e "${HI}2. Contains at least 27 upper or lower-case alphebetic characters$NORMAL"
grep -E -i --color=always '[a-z]{26}[a-z]+' $inputFile

echo -e "${HI}3. Contains more than 18 characters$NORMAL"
grep -E -i --color=always '.{19,}' $inputFile

echo -e "${HI}4. Contains exactly 10 characters$NORMAL"
grep -E -i --color=always '^.{10}$' $inputFile

echo -e "${HI}5. Contains a sequence between 6 and 8 upper or lower-case alphebetic characters$NORMAL"
grep -E -i --color=always '[a-z]{6,8}' $inputFile

echo -e "${HI}6. Contains a local phone number (123-4567)$NORMAL"
grep -E -i --color=always '^[0-9]{3}-[0-9]{4}' $inputFile

echo -e "${HI}7. Contains a valid URL on a line by itself$NORMAL"
grep -E -m10 --color=always '^(http|HTTP)://[a-zA-Z0-9.-]+\.(com|edu)$' $inputFile
