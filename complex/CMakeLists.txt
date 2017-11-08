cmake_minimum_required(VERSION 3.0)
project(complex)

set(CMAKE_CXX_STANDART 11)

set(SOURCE_FILES complex.h complex.cpp complex_test.cpp)
add_executable(complex ${SOURCE_FILES})