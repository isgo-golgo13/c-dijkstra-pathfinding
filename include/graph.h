#ifndef GRAPH_H
#define GRAPH_H

#include <stddef.h>

typedef struct {
    size_t node_count;
    int **edges;
} Graph;

// Create and destroy graph
Graph *create_graph(size_t node_count);
void destroy_graph(Graph *graph);

// Add edge
void add_edge(Graph *graph, size_t src, size_t dest, int weight);

#endif // GRAPH_H
