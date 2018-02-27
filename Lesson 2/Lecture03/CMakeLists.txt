cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
project(Lecture02)
add_executable(driver03 ${CMAKE_CURRENT_SOURCE_DIR}/driver03.cpp)
target_sources(driver03
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/point1.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/point1.h"
)