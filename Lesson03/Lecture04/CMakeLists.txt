cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
project(Lecture02)
add_executable(lecture4driver ${CMAKE_CURRENT_SOURCE_DIR}/lecture4driver.cpp)
target_sources(lecture4driver
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/location.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/location.h"
)