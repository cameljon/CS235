cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
project(inventory)
add_executable(inventory ${CMAKE_CURRENT_SOURCE_DIR}/driverinv.cpp)
target_sources(inventory
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/container.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/container.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inventory.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/inventory.h"
)