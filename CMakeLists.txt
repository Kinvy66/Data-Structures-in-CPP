cmake_minimum_required(VERSION 3.22)
project(data_structures_and_algorithm_cpp)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(ch1)
add_subdirectory(ch2)

add_subdirectory(test)

add_executable(data_structures_and_algorithm_cpp main.cpp)
