cmake_minimum_required(VERSION 3.20)
project(DijkstraC23 LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(dijkstra
    dijkstra-svc.c
    graph.c
    dijkstra.c
)

target_compile_options(dijkstra PRIVATE -Wall -Wextra -pedantic)
