cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
project(Lecture02)
add_executable(lecture02Driver ${CMAKE_CURRENT_SOURCE_DIR}/lecture02Driver.cpp)
target_sources(lecture02Driver
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/point.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/point.h"
)