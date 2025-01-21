cmake_minimum_required(VERSION 3.20)
project(DijkstraC LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/dijkstra-svc.c
    src/dijkstra.c
    src/graph.c
)

# Add the executable
add_executable(dijkstra ${SOURCES})

# Compiler options
target_compile_options(dijkstra PRIVATE -Wall -Wextra -pedantic)
