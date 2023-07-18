#include <stdio.h>
#include <stdlib.h>

// Maximum number of vertices
#define MAX_VERTICES 100

// Graph structure
struct Graph {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int visited[MAX_VERTICES];
};

// Function to create a new graph
struct Graph createGraph(int vertices) {
    struct Graph graph;
    graph.vertices = vertices;

    // Initialize adjacency matrix with 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph.adjacencyMatrix[i][j] = 0;
        }
    }

    // Initialize visited array with 0
    for (int i = 0; i < vertices; i++) {
        graph.visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int v, int w) {
    graph->adjacencyMatrix[v][w] = 1;
}

// Depth First Search traversal
void DFS(struct Graph* graph, int v) {
    graph->visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[v][i] && !graph->visited[i]) {
            DFS(graph, i);
        }
    }
}

// Driver code
int main() {
    // Create a graph
    struct Graph graph = createGraph(5);

    // Add edges
   addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 0, 3);
    addEdge(&graph, 1, 0);
    addEdge(&graph, 2, 0);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 0);
    addEdge(&graph, 3, 2);
    addEdge(&graph, 4, 2);
    addEdge(&graph,4,4);

    
    printf("Following is Depth First Traversal (starting from vertex 2):\n");

    // Perform DFS traversal
    DFS(&graph,3);

    return 0;
}
