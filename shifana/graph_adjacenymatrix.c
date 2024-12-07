#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// BFS Implementation
void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES], front = -1, rear = -1;
    int i;

    visited[start] = 1;
    queue[++rear] = start;
    
    printf("BFS starting from vertex %d: ", start);
    
    while (front != rear) {
        front++;
        int node = queue[front];
        printf("%d ", node);
        
        for (i = 0; i < vertices; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}


void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int visited[MAX_VERTICES], int node) {
    printf("%d ", node);
    visited[node] = 1;
    
    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, vertices, visited, i);
        }
    }
}


void dfs_topo(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int visited[MAX_VERTICES], int node, int stack[MAX_VERTICES], int *top) {
    visited[node] = 1;
    
    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs_topo(graph, vertices, visited, i, stack, top);
        }
    }
    
    stack[++(*top)] = node;
}

void topologicalSort(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES], top = -1;
    
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs_topo(graph, vertices, visited, i, stack, &top);
        }
    }
    
    printf("\nTopological Sort: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int vertices, u, v;
    

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    

    char labels[vertices][50];
    printf("Enter the labels for the vertices:\n");
    for (int i = 0; i < vertices; i++) {
        printf("Enter label for vertex %d: ", i);
        scanf("%s", labels[i]);
    }
    

    for (int i = 0; i < vertices; i++) {
        printf("\nFor vertex %s , choose vertices to connect to:\n", labels[i]);
// printf("Enter the indices of vertices to form edges, or -1 to stop.\n");
        while (1) {
            printf("Enter vertex index to connect (or -1 to stop): ");
            scanf("%d", &v);
            
            if (v == -1) break;  
            
            if (v >= 0 && v < vertices) {
                graph[i][v] = 1; 
                printf("Edge added from %s to %s.\n", labels[i], labels[v]);
            } else {
                printf("Invalid vertex index! Please enter a valid index.\n");
            }
        }
    }

    //Display the adjacency matrix
   printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
      for (int j = 0; j < vertices; j++) {
        printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

while(1){

    printf("\nEnter the starting vertex index for BFS(-1 to exit): ");
    scanf("%d", &u);
 if(u==-1){return 0;}
    bfs(graph, vertices, u);


    int visited[MAX_VERTICES] = {0};
    printf("\nEnter the starting vertex index for DFS(-1 to exit): ");
    scanf("%d", &u);
 if(u==-1){return 0;}
    printf("DFS starting from vertex %d: ", u);
    dfs(graph, vertices, visited, u);
    printf("\n");

  
   // printf("\nTopological Sort: \n");
    topologicalSort(graph, vertices);
}
    return 0;
}
