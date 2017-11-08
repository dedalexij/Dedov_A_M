cmake_minimum_required(VERSION 3.0)
project(rational)

set(CMAKE_CXX_STANDART 11)

set(SOURCE_FILES rational.h rational.cpp rational_test.cpp)
add_executable(rational ${SOURCE_FILES})