# AyoOS

Description TBD.

## Checkout

The code depends on the Raspberry Pi Pico SDK, which is added as a submodule. To checkout the SDK and other submodules do:

    git clone https://github.com/arturo182/AyoOS
    cd AyoOS
    git submodule update --init --recursive

## Build

Building the code is quite easy:

    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Debug ..
    make
