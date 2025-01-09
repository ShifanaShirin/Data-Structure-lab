#include <stdio.h>

int n, graph[10][10], visited[10] = {0}, inDegree[10];

void dfs(int node)
{
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

void bfs()
{
    int index = 0, nextIndex = 0, nodes[10];

    visited[1] = 1;
    nodes[nextIndex++] = 1;

    while (index < nextIndex)
    {
        int node = nodes[index++];
        printf("%d ", node);

        for (int i = 1; i <= n; i++)
        {
            if (graph[node][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                nodes[nextIndex++] = i;
            }
        }
    }
}

void topologicalSort()
{
    int stack[10], top = -1;
    
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            stack[++top] = i;
        }
    }

    while (top != -1)
    {
        int node = stack[top--];
        printf("%d ", node);

        for (int i = 1; i <= n; i++)
        {
            if (graph[node][i] == 1)
            {
                inDegree[i]--;
                if (inDegree[i] == 0)
                {
                    stack[++top] = i;
                }
            }
        }
    }
}

int main()
{
    int i, j, choice;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = 999;  
            if (graph[i][j] == 1)
                inDegree[j]++;
        }
    }

    while (1)
    {
        printf("\nChoose an algorithm to run:\n");
        printf("1. Depth First Search (DFS)\n");
        printf("2. Breadth First Search (BFS)\n");
        printf("3. Topological Sort\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("Depth First Search (DFS):\n");
            for (i = 0; i <= n; i++) visited[i] = 0;
            dfs(1);
            break;
        case 2:
            printf("Breadth First Search (BFS):\n");
            for (i = 0; i <= n; i++) visited[i] = 0;
            bfs();
            break;
        case 3:
            printf("Topological Sort:\n");
            topologicalSort();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
