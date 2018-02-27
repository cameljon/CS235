cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
project(nibbleOperDriver)
add_executable(nibbleOperDriver ${CMAKE_CURRENT_SOURCE_DIR}/nibbleOperDriver.cpp)
target_sources(nibbleOperDriver
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/nibbleOperHeader.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/nibbleOperImplementation.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/testNibbleOperHeader.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/testNibbleOperImplementation.cpp"
)