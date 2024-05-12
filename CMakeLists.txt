cmake_minimum_required(VERSION 3.28)
project(Da_proj2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Da_proj2
        src/main.cpp
        src/menu.h
        src/menu.cpp
        src/structs/shipping.h
        src/structs/shipping.cpp
        src/structs/stadium.h
        src/structs/stadium.cpp
        src/structs/tourism.h
        src/structs/tourism.cpp)
