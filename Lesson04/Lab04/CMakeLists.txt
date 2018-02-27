cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
project(Lecture02)
add_executable(nibbleDriver ${CMAKE_CURRENT_SOURCE_DIR}/nibbleDriver.cpp)
target_sources(nibbleDriver
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/nibbleImplementation.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/nibbleHeader.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/testNibbleImplementation.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/testNibbleHeader.h"
)