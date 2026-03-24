find_package(SDL2 REQUIRED)

add_executable(noahshpad_desktop
    hal.c
)

target_include_directories(noahshpad_desktop PRIVATE
    ${CMAKE_SOURCE_DIR}/hal
)

target_link_libraries(noahshpad_desktop
    app
    SDL2::SDL2
)