cmake_minimum_required(VERSION 3.20)
project(NWEN241_Assignment3)

set(CMAKE_CXX_STANDARD 17)

add_executable(t3test
        t3test.cpp
        vectordb.cpp
        abstractdb.cpp
)
