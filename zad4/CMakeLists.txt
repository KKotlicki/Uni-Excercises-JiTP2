cmake_minimum_required (VERSION 2.8.12)
project (zad4)

set(CMAKE_CXX_STANDARD 11)

include_directories(fltk/build graph_lib fltk)
link_directories(graph_lib/build fltk fltk/build fltk/build/lib)


add_executable (test tst_graph.cpp)
target_link_libraries(test libgraph_lib.a libfltk.a libfltk_images.a libgdi32.a libole32.a libuuid.a libcomctl32.a)