cmake_minimum_required(VERSION 3.21)
project(lab5 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab5 main.c)

include_directories(src)
add_subdirectory(src)

add_subdirectory(test)