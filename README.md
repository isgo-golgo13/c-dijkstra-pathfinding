# C (C23 Standard) Dijkstras Pathfinding Algorithm
C (C23) Dijkstras Pathfinding Algorithm

## Dijkstras Algorithm

This algorithm is a pathfinding algorithm to find the shortest path in the line of two nodes in a weighted graph. The algorithm is a `greedy` algorithm that functions through iteratively selecting the nearest `unvisited` node and updating the shortest path guages to its adjacent nodes.

- **Classification**: 
    - Single-source shortest path algorithm.
- **Applictation**: 
    - Works on graphs with non-negative edge weights.
- **Goal**: 
    - Finds the shortest path from a starting node (source) to a target node or all other nodes in the graph.
- **Approach**: 
    - Uses a priority queue (frequently developed with a low-heap) to efficiently select the next closest node.

## Workflow of Dijkstras Algorithm

- Initialize the starting node's distance to `0` and all other node distances to infinity.
- Flag the starting node as visited and process its adjacents by updating their shortest distances if a shorter path is found.
- Continuously pick the unvisited node with the shortest known distance, flag it as visited, and update its adjacents.
- Stop when all nodes are visited or the shortest path to the target node is determined.

## Application Scenarios

Dijkstras algorithm is a highly-efficient and foundational pathfinding algorithm. 

- **Routing and Navigation Applications**: 
    - Finding the shortest path in road networks.
- **Network Routing**:
    - Calculating shortest paths in data transmission.
- **Video Gaming**:
    - Pathfinding for characters or entities. 


## Extended Variants of Dijkstras Algorithm

- HC Pathfinding