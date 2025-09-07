#include <stdio.h>
#include <stdlib.h>

// Global declarations
int a[50][50], n;                // Adjacency matrix 'a' and number of vertices 'n'
int visited[50];                 // Array to track visited nodes
int q[20], front = -1, rear = -1;// Queue for BFS, using 'front' and 'rear' to track positions
int s[20], top = -1;             // Stack for DFS
int count = 0;                   // Counter (used if needed for various purposes)

// Function to perform Breadth-First Search (BFS)
void bfs(int start_vertex) {
    int i, current_vertex;

    // Mark the start vertex as visited and enqueue it
    visited[start_vertex] = 1;
    q[++rear] = start_vertex;  // Enqueue the start vertex
    
    printf("%d ", start_vertex); // Print the start vertex

    while (front != rear) {  // While the queue is not empty
        current_vertex = q[++front];  // Dequeue a vertex
        
        // Explore all adjacent vertices of the dequeued vertex
        for (i = 1; i <= n; i++) {
            if (a[current_vertex][i] == 1 && visited[i] == 0) {
                q[++rear] = i;       // Enqueue the connected vertex
                visited[i] = 1;      // Mark it as visited
                printf("%d ", i);    // Print the vertex
            }
        }
    }
}

// Function to perform Depth-First Search (DFS)
void dfs(int start_vertex) {
    int i;

    // Mark the start vertex as visited and push it onto the stack
    visited[start_vertex] = 1;
    s[++top] = start_vertex;

    printf("%d ", start_vertex);  // Print the start vertex

    // Explore all adjacent vertices of the start vertex
    for (i = 1; i <= n; i++) {
        if (a[start_vertex][i] == 1 && visited[i] == 0) {
            dfs(i);  // Recursively perform DFS on the unvisited adjacent vertices
        }
    }
}

int main() {
    int ch, start_vertex, i, j;

    // Input: Number of vertices in the graph
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    // Input: Adjacency matrix for the graph
    printf("\nEnter the adjacency matrix (use 1 for connected, 0 for not connected):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Initialize the visited array to mark all vertices as unvisited
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    // Input: Starting vertex for traversal
    printf("\nEnter the starting vertex: ");
    scanf("%d", &start_vertex);

    do {
        // Menu to choose between BFS, DFS, or exit
        printf("\n\n==> Menu:");
        printf("\n1. BFS: Print all nodes reachable from the starting node");
        printf("\n2. DFS: Print all nodes reachable from the starting node");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                // BFS
                printf("\nNodes reachable from starting vertex %d using BFS are: ", start_vertex);
                bfs(start_vertex);

                // Check for unreachable nodes
                for (i = 1; i <= n; i++) {
                    if (visited[i] == 0) {
                        printf("\nVertex %d is not reachable", i);
                    }
                }
                break;

            case 2:
                // Reset visited array for DFS
                for (i = 1; i <= n; i++) {
                    visited[i] = 0;
                }
                printf("\nNodes reachable from starting vertex %d using DFS are: ", start_vertex);
                dfs(start_vertex);
                break;

            case 3:
                // Exit
                exit(0);

            default:
                // Invalid choice
                printf("\nPlease enter a valid choice.");
        }

        // Reset visited array before the next iteration
        for (i = 1; i <= n; i++) {
            visited[i] = 0;
        }

        // Reset queue and stack pointers
        front = rear = -1;
        top = -1;

    } while (ch != 3);  // Loop until the user chooses to exit

    return 0;
}
