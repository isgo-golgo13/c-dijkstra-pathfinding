#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Graph *create_graph(size_t node_count) {
    Graph *graph = aligned_alloc(_Alignof(Graph), sizeof(Graph));
    if (!graph) {
        perror("Failed to allocate memory for graph");
        exit(EXIT_FAILURE);
    }

    graph->node_count = node_count;
    graph->edges = aligned_alloc(_Alignof(int *), node_count * sizeof(int *));
    if (!graph->edges) {
        perror("Failed to allocate memory for adjacency matrix");
        free(graph);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < node_count; i++) {
        graph->edges[i] = aligned_alloc(_Alignof(int), node_count * sizeof(int));
        if (!graph->edges[i]) {
            perror("Failed to allocate memory for adjacency list");
            for (size_t j = 0; j < i; j++) free(graph->edges[j]);
            free(graph->edges);
            free(graph);
            exit(EXIT_FAILURE);
        }
        memset(graph->edges[i], -1, node_count * sizeof(int)); // -1 indicates no edge
    }
    return graph;
}

void destroy_graph(Graph *graph) {
    for (size_t i = 0; i < graph->node_count; i++) {
        free(graph->edges[i]);
    }
    free(graph->edges);
    free(graph);
}

void add_edge(Graph *graph, size_t src, size_t dest, int weight) {
    if (src >= graph->node_count || dest >= graph->node_count) {
        fprintf(stderr, "Invalid edge (%zu -> %zu)\n", src, dest);
        return;
    }
    graph->edges[src][dest] = weight;
}
