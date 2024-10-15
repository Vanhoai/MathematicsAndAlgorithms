cmake_minimum_required(VERSION 3.29)
project(DataStructureAlgorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructureAlgorithms main.cpp
        complex.h
        complex.cpp
        data_structure/vector.h
        data_structure/vector.cpp
        data_structure/array.h
        data_structure/array.cpp
)
