cmake_minimum_required(VERSION 3.0)
project(vec3d)

set(CMAKE_CXX_STANDART 11)

set(SOURCE_FILES vec3d.h vec3d.cpp vec3d_test.cpp)
add_executable(vec3d ${SOURCE_FILES})