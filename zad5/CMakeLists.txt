cmake_minimum_required (VERSION 2.8.12)
project (zad4)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(fltk/build graph_lib fltk)
link_directories(graph_lib/build fltk fltk/build fltk/build/lib)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/mapa_test.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
include_directories(.)

add_executable (test figure_test.cpp)
target_link_libraries(test libgraph_lib.a libfltk.a libfltk_images.a libgdi32.a libole32.a libuuid.a libcomctl32.a figure.h)