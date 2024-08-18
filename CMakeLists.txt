cmake_minimum_required(VERSION 3.10)
project(Wisterl-System)

set(CMAKE_CXX_FLAGS "-Os -Ofast -ffunction-sections -fdata-sections -finline-functions -funroll-loops -fvectorize -ftree-vectorize -march=native")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_BUILD_TYPE Release)

add_executable(Wisterl-System Wisterl-System.cpp)