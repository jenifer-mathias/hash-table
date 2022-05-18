cmake_minimum_required(VERSION 3.20)
project(class-exercises)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        class-exercises
        HashTable.cpp
)

