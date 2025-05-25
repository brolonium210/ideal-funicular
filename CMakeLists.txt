cmake_minimum_required(VERSION 3.20)
project(t5test_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(t5test
        t5test.cpp
        abstractdb.cpp
        vectordb.cpp
)
