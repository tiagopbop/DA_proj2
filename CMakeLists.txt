cmake_minimum_required(VERSION 3.28)
project(Da_proj2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Da_proj2
        src/main.cpp
        src/menu.h
        src/menu.cpp
        src/structs/toy_sets.h
        src/structs/toy_sets.cpp
        src/structs/Graph.h
        src/structs/Realworld.h
        src/structs/Realworld.h
        src/structs/extra.h
        src/structs/Realworld.cpp
        src/structs/extra.cpp
        src/structs/MutablePriorityQueue.h
)
