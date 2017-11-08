cmake_minimum_required(VERSION 3.0)
project(rationalT)

set(CMAKE_CXX_STANDART 11)

set(SOURCE_FILES rationalT.h rationalT_test.cpp)
add_executable(rationalT ${SOURCE_FILES})