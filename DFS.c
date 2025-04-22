#include <stdio.h>
#define MAX 100
int adj[MAX][MAX], visited[MAX];
void DFS(int v, int n)
{
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && !visited[i])
        {
            DFS(i, n);
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
    printf("DFS Traversal: ");
    DFS(start, n);
    return 0;
}