#!/usr/bin/env bash

TextSpam() {
    # this is how you define a parameters!
    local count=$1
    
    local text="This is a text spam function!"

    for (( i=1; i <= count; i++ )); do
        echo "$i. $text"
    done
}

TextSpam $1