cmake_minimum_required(VERSION 3.19)
project(design_pattern)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
set(CMAKE_CXX_STANDARD 17)

add_executable(design_pattern main.cpp AbstractSportProduct.h commandPattern.cpp commandPattern.h MementoPattern.cpp MementoPattern.h)