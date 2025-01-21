#include "graph.h"
#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Graph *graph = create_graph(5);
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 2, 3);
    add_edge(graph, 1, 2, 1);
    add_edge(graph, 1, 3, 2);
    add_edge(graph, 2, 1, 4);
    add_edge(graph, 2, 3, 8);
    add_edge(graph, 2, 4, 2);
    add_edge(graph, 3, 4, 7);
    add_edge(graph, 4, 3, 9);

    size_t num_nodes = 5;
    int *distances = malloc(num_nodes * sizeof(int));

    dijkstra(graph, 0, distances);

    printf("Shortest distances from node 0:\n");
    for (size_t i = 0; i < num_nodes; i++) {
        printf("Node %zu: %d\n", i, distances[i]);
    }

    free(distances);
    destroy_graph(graph);
    return 0;
}
