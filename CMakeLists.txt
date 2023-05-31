cmake_minimum_required(VERSION 3.23)
project(FileSystem C)

set(CMAKE_C_STANDARD 99)

add_executable(FileSystem main.c filesystem.h filesystem.c)
