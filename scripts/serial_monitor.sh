#!/bin/bash

device=(/dev/serial/by-id/usb-Raspberry_Pi_Pico_*)
if [[ ! -e ${device[0]} ]]; then
    echo "Waiting for Pico device to be connected"
    for i in {1..5}; do
        echo -n "."

        device=(/dev/serial/by-id/usb-Raspberry_Pi_Pico_*)
        if [ -e ${device[0]} ]; then
            echo
            break
        fi
        sleep 1
    done

    if [ ${#device[@]} -eq 0 ]; then
        echo "Timed out waiting for Pico device"
        exit 1
    fi
fi

echo "Found Pico device: ${device[0]}"
stty -F "${device[0]}" 115200
cat "${device[0]}"
