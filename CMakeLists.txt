cmake_minimum_required(VERSION 3.19)
project(onion_gen_addresses C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(onion_gen_addresses
        main.c
        main.h)
