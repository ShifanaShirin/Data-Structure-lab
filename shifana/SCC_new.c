#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX], transpose[MAX][MAX], visited[MAX], n;
int stack[MAX], top = -1;

// Function to perform DFS on the graph
void dfs(int graph[MAX][MAX], int node)
{
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 1; i <= n; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            dfs(graph, i);
        }
    }
}

// Function to fill the stack with nodes in the order of finish times
void dfs_fill_stack(int graph[MAX][MAX], int node)
{
    visited[node] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            dfs_fill_stack(graph, i);
        }
    }

    stack[++top] = node; // Push node to stack after finishing DFS
}

// Function to reverse the graph
void reverseGraph()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            transpose[i][j] = graph[j][i]; // Reverse the edges
        }
    }
}

// Function to find all strongly connected components
void kosaraju()
{
    // Step 1: DFS to fill stack with finish time order
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs_fill_stack(graph, i);
        }
    }

    // Step 2: Reverse the graph
    reverseGraph();

    // Step 3: DFS on reversed graph, using the order in the stack
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    printf("\nStrongly Connected Components:\n");
    while (top != -1)
    {
        int node = stack[top--];

        if (!visited[node])
        {
            printf("SCC: ");
            dfs(transpose, node);  // Perform DFS on the reversed graph
            printf("\n");
        }
    }
}

int main()
{
    int i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Find and print Strongly Connected Components using Kosaraju's algorithm
    kosaraju();

    return 0;
}
