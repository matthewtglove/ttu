#!/usr/bin/env bash

delay=$1
if [ -z "$delay" ]; then
    echo "Error: No delay time provided."
    exit 1
fi

echo "Starting delay of $delay seconds..."
# On the sleep, the script is going to pause. It will return all its cycles to the system.
sleep "$delay"