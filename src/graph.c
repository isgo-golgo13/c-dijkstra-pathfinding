#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Graph *create_graph(size_t node_count) {
    if (node_count == 0) {
        fprintf(stderr, "Invalid graph size: node_count must be > 0\n");
        return NULL;
    }

    // Allocate memory for the Graph structure
    Graph *graph = malloc(sizeof(Graph));
    if (!graph) {
        perror("Failed to allocate memory for graph");
        exit(EXIT_FAILURE);
    }

    graph->node_count = node_count;

    // Allocate memory for the adjacency list (array of int pointers)
    graph->edges = malloc(node_count * sizeof(int *));
    if (!graph->edges) {
        perror("Failed to allocate memory for adjacency list");
        free(graph);
        exit(EXIT_FAILURE);
    }

    // Allocate memory for each row in the adjacency matrix
    for (size_t i = 0; i < node_count; i++) {
        graph->edges[i] = malloc(node_count * sizeof(int));
        if (!graph->edges[i]) {
            perror("Failed to allocate memory for adjacency matrix row");
            // Free previously allocated rows
            for (size_t j = 0; j < i; j++) {
                free(graph->edges[j]);
            }
            free(graph->edges);
            free(graph);
            exit(EXIT_FAILURE);
        }

        // Initialize the row to -1 (no edge)
        memset(graph->edges[i], -1, node_count * sizeof(int));
    }

    return graph;
}


void add_edge(Graph *graph, size_t src, size_t dest, int weight) {
    if (src >= graph->node_count || dest >= graph->node_count) {
        fprintf(stderr, "Invalid edge (%zu -> %zu)\n", src, dest);
        return;
    }
    graph->edges[src][dest] = weight;
}

void destroy_graph(Graph *graph) {
    for (size_t i = 0; i < graph->node_count; i++) {
        free(graph->edges[i]);
    }
    free(graph->edges);
    free(graph);
}
