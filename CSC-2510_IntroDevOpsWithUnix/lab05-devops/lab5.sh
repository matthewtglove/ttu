#!/bin/bash

if [ $# -ne 2 ]; then
	echo "The number of args is invalid. Expected 2."
	exit 1
fi

if [ ! -f $1 ]; then
	echo "File $1 does not exist."
	exit 1
fi

while IFS= read line; 
do
	if [ $line = $2 ]; then
		echo "$2 already exists in file $1!"
		exit 0
	fi
# This says use the file as input
done < $1

echo $2 >> $1
echo "$2 was added to the file $1!"
