#!/usr/bin/env bash

color=$1

if [ "$color" = "red" ]; then
    echo "No way you guessed the color"
else
    echo "Wrong color, try again"
fi

userGuess=$2
correctAnswer=50

if [ "$userGuess" -lt "$correctAnswer" ]; then
    echo "You're too low"
fi

if [ "$userGuess" -gt "$correctAnswer" ]; then
    echo "You're too high"
fi

if [ "$userGuess" -eq "$correctAnswer" ]; then
    echo "You guessed it!"
fi

exit 0