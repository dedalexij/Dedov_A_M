cmake_minimum_required(VERSION 3.0)
project(array)

set(CMAKE_CXX_STANDART 11)

set(SOURCE_FILES array.h array.cpp array_test.cpp)
add_executable(array ${SOURCE_FILES})