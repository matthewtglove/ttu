#!/usr/bin/env bash

names=$@

for name in $names; do
    echo -e "\nHello there, $name!"
    if [ "$name" = "Sheri" ]; then
        echo -e "Hi beautiful."
    fi
done

exit 0