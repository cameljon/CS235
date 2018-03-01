cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
project(statesDriver)
add_executable(statesDriver ${CMAKE_CURRENT_SOURCE_DIR}/statesDriver.cpp)
target_sources(statesDriver
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/states.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/states.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/testStates.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/testStates.h"
)