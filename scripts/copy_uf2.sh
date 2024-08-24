#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "Usage: $0 <firmware.uf2>"
    exit 1
fi

uf2=$1

if [[ ! -f ${uf2} ]]; then
    echo "File not found: ${uf2}"
    exit 1
fi

dst="/run/media/${USER}/RP2350"

device=(/dev/serial/by-id/usb-Raspberry_Pi_Pico_*)
if [[ -e ${device[0]} ]]; then
    echo "Found Pico device: ${device[0]}, resetting"
    stty -F ${device[0]} 1200
fi

if [[ ! -d ${dst} ]]; then
    echo "Waiting for ${dst}"
    for i in {1..15}; do
        echo -n "."

        if [[ -d ${dst} ]]; then
            echo
            break
        fi
        sleep 1
    done

    if [[ ! -d ${dst} ]]; then
        echo "Timed out waiting for ${dst}"
        exit 1
    fi
fi

echo "Copying ${uf2} to ${dst}"
cp "${uf2}" "${dst}"
