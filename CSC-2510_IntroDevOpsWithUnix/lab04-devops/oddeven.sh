#!/bin/bash

minute=$(date +%M)
if (((($((10#$minute))%2))==0)); then
	echo "The time is even"
else
	echo "The time is odd"
fi
