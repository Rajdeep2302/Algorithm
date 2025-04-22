#include <stdio.h>
#define MAX 100
int adj[MAX][MAX], visited[MAX];
int queue[MAX], front = -1, rear = -1;
void enqueue(int v)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}
int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}
void BFS(int start, int n)
{
    visited[start] = 1;
    enqueue(start);
    while (front <= rear)
    {
        int node = dequeue();
        printf("%d ", node);
        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}
int main()
{
    int n, start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%dx%d) with 0/1:\n", n, n);
         for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
         scanf("%d", &adj[i][j]);
         printf("Enter starting node (0 to %d): ", n - 1);
         scanf("%d", &start);
         printf("BFS Traversal: ");
         BFS(start, n);
         return 0;
}
