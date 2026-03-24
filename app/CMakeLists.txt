add_library(app STATIC
    main.c
    #keymap.c
    display.c
)

target_include_directories(app PUBLIC
    ${CMAKE_SOURCE_DIR}/hal
    ${CMAKE_SOURCE_DIR}/app
)