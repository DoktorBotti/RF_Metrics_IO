cmake_minimum_required(VERSION 3.8)
project(inforf LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
add_library(json_lib INTERFACE)
target_include_directories(json_lib INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/json>)

add_library(rf_io_lib
        IOData.cpp
        IOData.h
        )
target_include_directories(rf_io_lib SYSTEM INTERFACE json_lib)
target_link_libraries(rf_io_lib  json_lib)