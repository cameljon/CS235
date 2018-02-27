cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
project(Lecture02)
add_executable(clockLabPart2Driver ${CMAKE_CURRENT_SOURCE_DIR}/clockLabPart2Driver.cpp)
target_sources(clockLabPart2Driver
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/clockPart2.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/clockPart2.h"
)