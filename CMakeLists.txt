cmake_minimum_required(VERSION 3.20)

if(TARGET_PLATFORM STREQUAL "pico")
    include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
endif()

project(noahshpad C CXX ASM)
set(CMAKE_C_STANDARD 11)

add_subdirectory(app)

if(TARGET_PLATFORM STREQUAL "pico")
    pico_sdK_init()
    add_subdirectory(target/pico)
elseif(TARGET_PLATFORM STREQUAL "desktop")
    add_subdirectory(target/desktop)
else()
    message(FATAL_ERROR "Set -DTARGET_PLATFORM=pico or desktop")
endif()