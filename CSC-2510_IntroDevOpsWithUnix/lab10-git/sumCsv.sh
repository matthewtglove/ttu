#!/bin/bash

if [ $# != 1 ]; then
    echo "The number of args is invalid. Expected 1."
    exit 1
fi
if [ ! -f $1 ]; then
    echo "File $1 does not exist."
    exit 1
fi

while IFS=, read -r column1 column2; 
do
	echo "$column1 plus$column2 = $(($column1 + $column2))"
done < $1