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
        data_structure/tree/avl_tree.cpp
        data_structure/graph/cycle_directed.cpp
        data_structure/graph/bipartite_graph.cpp
        data_structure/graph/cycle_undirected.cpp
        data_structure/graph/strong_connected_component.cpp
        data_structure/graph/prime_priority.cpp
        data_structure/graph/prim_queue.cpp
        data_structure/graph/mst.cpp
        data_structure/graph/matrix_path.cpp
        data_structure/graph/matrix.cpp
        data_structure/graph/kruskal.cpp
        data_structure/graph/find_path.cpp
        data_structure/graph/topo_sort.cpp
        data_structure/graph/prime.cpp
)
