#!/bin/bash

month=$(date +%m)
minute=$(date +%M)
loopCount=$((10#$month + 10#$minute))
# echo $loopCount

for ((i = 1 ; i <= $loopCount ; i++))
do
	echo "Iteration $i out of $loopCount. $(($loopCount - $i)) iterations remaining."
done
