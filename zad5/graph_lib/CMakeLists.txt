cmake_minimum_required(VERSION 3.21)
project(graph_lib)

set(CMAKE_CXX_STANDARD 14)

add_compile_definitions(WIN32)

add_library(graph_lib Graph.cpp GUI.cpp Simple_window.cpp Window.cpp)
include_directories(../fltk/build)
include_directories(../fltk/)
link_directories('../fltk/build)
target_link_libraries(graph_lib FL/abi-version.h)
