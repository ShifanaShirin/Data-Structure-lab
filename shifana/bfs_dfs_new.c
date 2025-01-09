#include <stdio.h>

int n, graph[10][10], visited[10] = {0}, queue[10], front = -1, rear = -1, inDegree[10];

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

void enqueue(int node)
{
    if (rear == 9)
        printf("Queue Full\n");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = node;
    }
}

int dequeue()
{
    int node;
    if (front == -1)
        printf("Queue Empty\n");
    else
    {
        node = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }
    return node;
}

void bfs()
{
    visited[1] = 1;
    enqueue(1);
    
    while (front != -1)
    {
        int node = dequeue();
        printf("%d ", node);
        
        for (int i = 1; i <= n; i++)
        {
            if (graph[node][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

void topologicalSort()
{
    int stack[10], top = -1;
    
    // Initialize stack with nodes having zero in-degree
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            stack[++top] = i;
        }
    }
    
    // Perform topological sort
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
                graph[i][j] = 999;  // For Prim's Algorithm, no edge should be 0 (except diagonal)
            if (graph[i][j] == 1)
                inDegree[j]++;  // For Topological Sort (in-degree calculation)
        }
    }

    // Menu for choosing which algorithm to run
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
            for (i = 0; i <= n; i++) visited[i] = 0;  // Reset visited for DFS
            dfs(1);
            break;
        case 2:
            printf("Breadth First Search (BFS):\n");
            for (i = 0; i <= n; i++) visited[i] = 0;  // Reset visited for BFS
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
