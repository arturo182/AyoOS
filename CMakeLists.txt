cmake_minimum_required(VERSION 3.13)

set(PICO_PLATFORM "rp2350")
set(PICO_BOARD "rp2xxx_stamp_carrier_xl")
set(PICO_BOARD_HEADER_DIRS ${CMAKE_CURRENT_LIST_DIR}/boards)

include(3rdparty/pico-sdk/pico_sdk_init.cmake)

project(ayo_os)

pico_sdk_init()

set(LV_CONF_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/lv_conf.h CACHE STRING "" FORCE)

add_subdirectory(3rdparty/sparkfun-pico/sparkfun_pico)
add_subdirectory(3rdparty/lvgl)
add_subdirectory(src)
