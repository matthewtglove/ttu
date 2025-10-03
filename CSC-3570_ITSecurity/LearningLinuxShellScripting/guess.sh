#!/usr/bin/env bash

# A random number 1-100
winningNumber=$(( $RANDOM % 100 + 1 ))
luckyGuess=0
guessCount=0

while [ $luckyGuess -ne $winningNumber ]; do
    read -p "Enter your lucky guess (1-100): " guess
    if [[ ! $guess =~ ^[0-9]+$ ]]; then
        echo "Your lucky guess must be an integer!"
        continue
    fi
    if [ $guess -lt 1 ] || [ $guess -gt 100 ]; then
        echo "Your lucky guess must be between 1 and 100!"
        continue
    fi
    if [ $guess -lt $winningNumber ]; then
        echo "Too low! Try again."
        ((guessCount++))
        continue
    fi
    if [ $guess -gt $winningNumber ]; then
        echo "Too high! Try again."
        ((guessCount++))
        continue
    fi

    luckyGuess=$guess

    echo -e "\033[32mCongratulations! You've guessed the correct number $winningNumber in \033[36m$guessCount guesses\033[32m!\033[0m"
done

exit 0