cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
project(Lecture02)
add_executable(numberDriver ${CMAKE_CURRENT_SOURCE_DIR}/numberDriver.cpp)
target_sources(numberDriver
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/Number.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Number.h"
)