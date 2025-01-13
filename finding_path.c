#include <stdio.h>             // Standard input/output library
#include <limits.h>             // Library for defining constants like INT_MAX
#define MAX 10                 // Maximum number of nodes (can be changed if needed)
#define INF INT_MAX            // Define INF as the maximum integer value to represent unreachable nodes

// Function to implement Bellman-Ford Algorithm
void bellmanFord(int n, int input[MAX][MAX], int src) {
    int distance[MAX];  // Array to store the shortest distance from source to each vertex

    // Initialize distances with INF, except for the source node which is set to 0
    for (int i = 0; i < n; i++) {
        distance[i] = INF;  // Initially, set all distances to INF
    }
    distance[src] = 0;  // Distance from source to itself is 0

    // Relax all edges (n-1) times
    for (int k = 0; k < n - 1; k++) {  
        for (int i = 0; i < n; i++) {  
            for (int j = 0; j < n; j++) {  
                // If there is an edge and the distance can be reduced, update it
                if (input[i][j] != 0 && distance[i] != INF && distance[i] + input[i][j] < distance[j]) {  
                    distance[j] = distance[i] + input[i][j];  // Update the distance to the adjacent node
                }  
            }  
        }  
    }

    // Check for negative-weight cycles
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {  
            // If the distance can still be updated, then a negative-weight cycle exists
            if (input[i][j] != 0 && distance[i] != INF && distance[i] + input[i][j] < distance[j]) {  
                printf("Graph contains a negative-weight cycle\n");  
                return;  // Exit the function if a negative-weight cycle is detected
            }  
        }  
    }

    // Print the shortest distance from the source to each vertex
    printf("Vertex Distance from Source %d:\n", src);  
    for (int i = 0; i < n; i++) {  
        if (distance[i] == INF) {  // If the distance is still INF, no path exists
            printf("Vertex %d: INF\n", i);  
        } else {  // Otherwise, print the shortest distance
            printf("Vertex %d: %d\n", i, distance[i]);  
        }  
    }  
}

// Main function to take input and call Bellman-Ford function
int main() {
    int n, input[MAX][MAX];  // Variables for the number of nodes and the cost matrix
    int src;  // Variable for the source node

    // Get the total number of nodes from the user
    printf("Enter the total number of nodes: ");  
    scanf("%d", &n);  

    // Get the cost matrix (adjacency matrix) from the user
    printf("Enter the cost matrix of your graph (use 0 for no direct edge):\n");  
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {  
            scanf("%d", &input[i][j]);  // Read the weight of the edge between node i and node j
        }  
    }

    // Get the source node from the user
    printf("Enter the source node: ");  
    scanf("%d", &src);  

    // Call the Bellman-Ford function to calculate shortest paths
    bellmanFord(n, input, src);  

    return 0;  
}
