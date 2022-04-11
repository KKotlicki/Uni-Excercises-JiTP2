cmake_minimum_required(VERSION 3.21)
project(zad3)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/bad.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/good.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
include_directories(.)

add_executable(zad3 zad_1.cpp figure.h)
