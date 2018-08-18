cmake_minimum_required(VERSION 3.7)
project(dft_demo_base)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c dft_process.c dft_process.h)
add_executable(dft_demo_base ${SOURCE_FILES})