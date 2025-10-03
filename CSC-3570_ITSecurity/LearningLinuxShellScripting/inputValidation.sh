#!/usr/bin/env bash

valid=0

while [ $valid -eq 0 ]; do
    read -p "Please enter your name and age (e.g., John 30): " name age
    if [[ (-z $name) || (-z $age) ]]; then
        echo "Error: Both name and age are required."
        continue
    fi
    if [[ ! $name =~ ^[A-Za-z]+$ ]]; then
        echo "Error: Name must contain only letters."
        continue
    fi
    if [[ ! $age =~ ^[0-9]+$ ]]; then
        echo "Error: Age must be a number."
        continue
    fi

    valid=1
done

echo "Hello, $name. You are $age years old."

exit 0