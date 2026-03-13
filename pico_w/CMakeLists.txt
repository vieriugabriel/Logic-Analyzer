cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(logic_analyzer C CXX ASM)
set(CMAKE_C_STANDARD 11)

pico_sdk_init()

add_executable(logic_analyzer
    src/main.c
    src/i2c_capture.c
)

pico_generate_pio_header(logic_analyzer 
    ${CMAKE_CURRENT_LIST_DIR}/src/i2c_capture.pio
)

target_link_libraries(logic_analyzer
    pico_stdlib
    hardware_pio
)

pico_enable_stdio_usb(logic_analyzer 1)
pico_enable_stdio_uart(logic_analyzer 0)

pico_add_extra_outputs(logic_analyzer)