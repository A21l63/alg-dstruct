cmake_minimum_required(VERSION 3.21)
project(stack C)

set(CMAKE_CPP_STANDARD 17)

include_directories(/Lib1)

add_executable(src colouring.h colouring.c)
