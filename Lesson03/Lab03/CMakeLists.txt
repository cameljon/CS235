cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
project(Lecture02)
add_executable(FullNameDriver ${CMAKE_CURRENT_SOURCE_DIR}/FullNameDriver.cpp)
target_sources(FullNameDriver
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/FullName.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/FullName.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/FullNameTesterImplementation.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/FullNameTester.h"

)