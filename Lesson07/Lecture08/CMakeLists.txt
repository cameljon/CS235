cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
project(drive08)
add_executable(drive08 ${CMAKE_CURRENT_SOURCE_DIR}/drive08.cpp)
target_sources(drive08
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/PointB.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/PointB.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/Window.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Window.h"
)