add_executable(ayo_os
    main.c
)
add_subdirectory(drivers)

add_compile_options(-Wall -Wextra -Wpedantic)

target_include_directories(ayo_os PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(ayo_os
    hardware_spi
    lvgl
    lvgl_demos
    pico_stdlib
    sparkfun_pico
)

# binary info in flash
pico_set_program_name(ayo_os "AyoOS")
pico_set_program_version(ayo_os "0.1.0")

# printf targets
pico_enable_stdio_usb(ayo_os 1)
pico_enable_stdio_uart(ayo_os 1)

# create map/bin/hex/uf2 file in addition to elf
pico_add_extra_outputs(ayo_os)
