#!/bin/bash

if [ $# != 1 ]; then
    echo "The number of args is invalid. Expected 1."
    exit 1
fi
if [ ! -f $1 ]; then
    echo "File $1 does not exist."
    exit 1
fi

hostArray=( )
count=1

function readHosts {
    tempArray=$( cat $1 )
    for x in $tempArray; do
        hostArray[$count]=$x
        count=$(($count+1))
    done
}
readHosts $@

selectedHost=""

function pickHost {
    for i in "${!hostArray[@]}"; do
        echo "$((i)) - ${hostArray[$i]}"
    done

    # input validation
    hostIndex=-1
    hostCount=${#hostArray[@]}
    while [ $hostIndex -lt 0 ] || [ $hostIndex -ge $hostCount ]; do
        input=0
        read -p "Select a host (1-$hostCount): " input

        hostIndex=$(($input - 1))
    done

    selectedHost=${hostArray[$hostIndex]}
}

userChoice=""
while [ userChoice != "q" ]
do
    echo "n: nslookup \$host"
    echo "p: ping -c 1 \$host"
    echo "s: ssh \$user@\$host"
    echo "h: hostname"
    echo "i: ifconfig -a"
    echo "q: quit"

    read -p "Select menu option: " userChoice

    case $userChoice in
        [nN]*)
            pickHost
            nslookup $selectedHost
            ;;
        [pP]*)
            pickHost
            ping -c 1 $selectedHost
            ;;
        [sS]*)
            read -p "What username should be used: " user
            pickHost
            ssh $user@$host
            ;;
        [hH]*)
            hostname
            ;;
        [iI]*)
            ifconfig -a
            ;;
        [qQ]*)
            # This is redundant as the while loop handles `q` for quit
            break;
            ;;
        *)
            echo "Invalid menu option."
            ;;
    esac
    echo ""
done