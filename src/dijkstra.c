#include "dijkstra.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <pthread.h>
#include <limits.h>

void dijkstra(const Graph *graph, size_t source, int *distances) {
    size_t n = graph->node_count;
    bool *visited = calloc(n, sizeof(bool));
    if (!visited) {
        perror("Failed to allocate memory for visited array");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < n; i++) {
        distances[i] = INT_MAX; // Initialize distances to infinity
    }
    distances[source] = 0;

    for (size_t i = 0; i < n - 1; i++) {
        int min_distance = INT_MAX;
        size_t min_index = 0;

        // Find the nearest unvisited node
        for (size_t v = 0; v < n; v++) {
            if (!visited[v] && distances[v] <= min_distance) {
                min_distance = distances[v];
                min_index = v;
            }
        }

        visited[min_index] = true;

        // Update distances of neighboring nodes
        for (size_t v = 0; v < n; v++) {
            int edge_weight = graph->edges[min_index][v];
            if (edge_weight != -1 && !visited[v] && distances[min_index] != INT_MAX &&
                distances[min_index] + edge_weight < distances[v]) {
                distances[v] = distances[min_index] + edge_weight;
            }
        }
    }

    free(visited);
}
