# AyoOS

Description TBD.

## Checkout

The code depends on the Raspberry Pi Pico SDK, which is added as a submodule. Because the Pico SDK includes TinyUSB as a module, it is not recommended to do a recursive submodule init, and rather follow these steps:

    git clone https://github.com/arturo182/AyoOS
    cd AyoOS
    git submodule update --init
    cd 3rdparty/pico-sdk
    git submodule update --init

## Build

Building the code is quite easy:

    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Debug ..
    make
