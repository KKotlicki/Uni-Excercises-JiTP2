cmake_minimum_required(VERSION 3.21)
project(zad4)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
include_directories(.)

add_executable(zad4 tst_graph.cpp)
