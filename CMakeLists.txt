cmake_minimum_required(VERSION 3.25)
project(Wisterl-System)

set(CMAKE_CXX_FLAGS "-std=c++26 -Os -Ofast -ffunction-sections -fdata-sections -finline-functions -funroll-loops -fvectorize -ftree-vectorize -march=native")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# set(CMAKE_BUILD_TYPE Release)

add_executable(Wisterl-System src/Wisterl-System.cpp)

add_custom_command(TARGET  ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_STRIP} "$<TARGET_FILE:${PROJECT_NAME}>"
        COMMENT "Strip debug symbols done on final binary.")
