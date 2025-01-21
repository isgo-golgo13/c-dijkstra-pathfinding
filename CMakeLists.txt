cmake_minimum_required(VERSION 3.20)
project(DijkstraC23 LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Specify source files
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

set(SOURCES
    ${SRC_DIR}/dijkstra-svc.c
    ${SRC_DIR}/dijkstra.c
    ${SRC_DIR}/graph.c
)

# Add the executable
add_executable(dijkstra ${SOURCES})

# Include directories
target_include_directories(dijkstra PRIVATE ${INCLUDE_DIR})

# Compiler options
target_compile_options(dijkstra PRIVATE -Wall -Wextra -pedantic -O2)
