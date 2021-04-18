cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
set(projname "elitecontroller")
project(${projname} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBOOST_MATH_DISABLE_FLOAT128")
pico_sdk_init()

#include(example_auto_set_url.cmake)

add_executable(${projname}
        main.c
        controls.c 
        )

target_link_libraries(${projname} pico_stdlib)
pico_add_extra_outputs(${projname})

