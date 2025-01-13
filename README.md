# ComputingShortestPath
This project implements the Bellman-Ford algorithm to find the shortest paths from a source node to all other nodes in a graph. The algorithm can handle graphs with negative-weight edges and also detect negative-weight cycles in the graph.

"Project Overview":

The Bellman-Ford algorithm computes the shortest paths in a graph from a given source vertex to all other vertices. It works by iteratively relaxing the edges of the graph and can handle negative weights, unlike Dijkstra's algorithm. It also detects negative-weight cycles, which can lead to infinite loop scenarios.

"Key Features":

Shortest Path Calculation: Computes the shortest distance from the source to every other vertex in the graph.
Negative-Weight Cycle Detection: Checks if the graph contains a negative-weight cycle, which can cause incorrect results.
Cost Matrix Input: The graph is represented as an adjacency matrix where the value at position (i, j) denotes the weight of the edge between vertex i and vertex j.

"Algorithm":

The Bellman-Ford algorithm works in n-1 iterations (where n is the number of nodes), and in each iteration, it relaxes the edges by checking if the distance to a vertex can be reduced by traveling through another vertex.

Relaxation: If distance[i] + input[i][j] < distance[j], then update distance[j].
Negative-Weight Cycle Check: After n-1 iterations, we check one more time to see if any distance can be further reduced. If it can, the graph contains a negative-weight cycle.

The graph is represented as a cost matrix where:
Each element input[i][j] represents the weight of the edge between vertex i and vertex j.
The maximum limit for the number of nodes is set to 10 for simplicity.
If there is no direct edge between the vertices, the value should be 0.
Before running the project, ensure that your system has a C compiler. You can use GCC or any other compiler to run the program.

