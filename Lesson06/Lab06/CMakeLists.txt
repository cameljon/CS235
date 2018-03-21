cmake_minimum_required(VERSION 3.6.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
project(Friends)
add_executable(Friends ${CMAKE_CURRENT_SOURCE_DIR}/friendsDriver.cpp)
target_sources(Friends
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/Friends.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Friends.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/FullNameB.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/FullNameB.h"
)