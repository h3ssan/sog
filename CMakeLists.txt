cmake_minimum_required(VERSION 3.19)
project(simple_onion_generation C)

set(CMAKE_C_FLAGS "-std=c89 -static ${CMAKE_C_FLAGS}")

include_directories(.)

add_executable(sog
        src/sources/main.c
        src/headers/main.h
        src/sources/validation.c
        src/headers/validation.h)
