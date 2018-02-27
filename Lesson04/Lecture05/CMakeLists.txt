cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
project(Lecture02)
add_executable(cis235Lect05driver ${CMAKE_CURRENT_SOURCE_DIR}/cis235Lect05driver.cpp)
target_sources(cis235Lect05driver
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/Ssn.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Ssn.h"
)