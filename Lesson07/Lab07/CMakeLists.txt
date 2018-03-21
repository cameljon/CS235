cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
project(PersonLabDriver)
add_executable(PersonLabDriver ${CMAKE_CURRENT_SOURCE_DIR}/PersonLabDriver.cpp)
target_sources(PersonLabDriver
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/FullNameB.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/FullNameB.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/Person.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Person.h"
)