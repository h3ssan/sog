cmake_minimum_required(VERSION 3.19)
project(simple_onion_generation C)

set(CMAKE_C_FLAGS "-std=c89 -static ${CMAKE_C_FLAGS}")

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(sog
        src/main.c
        include/sog/main.h
        src/validation.c
        include/sog/validation.h)
