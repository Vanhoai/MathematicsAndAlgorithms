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
        data_structure/stack/stack.cpp
        data_structure/linked_list/linked_list.cpp
        data_structure/queue/deque.cpp
        data_structure/tree/binary_tree.cpp
        data_structure/tree/segment_tree.cpp
)
