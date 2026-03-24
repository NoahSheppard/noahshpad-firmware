add_executable(noahshpad_pico
    hal.c
)

target_include_directories(noahshpad_pico PRIVATE
    ${CMAKE_SOURCE_DIR}/hal
)

target_link_libraries(noahshpad_pico
    app
    pico_stdlib
    hardware_i2c
    hardware_gpio
)

pico_enable_stdio_usb(noahshpad_pico 1)
pico_enable_stdio_uart(noahshpad_pico 0)
pico_add_extra_outputs(noahshpad_pico)