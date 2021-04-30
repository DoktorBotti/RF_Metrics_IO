cmake_minimum_required(VERSION 3.8)
project(inforf LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(rf_io_lib
        IOData.cpp
        IOData.h
        json.hpp
        )
