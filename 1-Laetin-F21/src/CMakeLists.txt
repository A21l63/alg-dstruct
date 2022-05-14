cmake_minimum_required(VERSION 3.21)
project(tree C)

set(CMAKE_CPP_STANDARD 23)

include_directories(/Lib1)

add_executable(src
        tree.c
        tree.h
        )
