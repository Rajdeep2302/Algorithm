#include <stdio.h>
#define INF 9999999
#define V 100

int main()
{
    int n, cost[V][V], visited[V] = {0}, no_edges = 0;
    int x, y, min;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the cost adjacency matrix (use 9999999 for no edge):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initially mark the first vertex as visited
    visited[0] = 1;

    // Print the MST edges
    printf("Edge : Weight\n");

    // While the number of edges in the MST is less than n-1
    while (no_edges < n - 1)
    {
        min = INF;

        // Traverse all vertices and check for the minimum weight edge
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            { // Check only visited vertices
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    { // Find the minimum edge
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        // Print the selected edge and its weight
        printf("%d - %d : %d\n", x + 1, y + 1, min); // +1 for 1-based index

        // Mark the second vertex as visited
        visited[y] = 1;

        // Increment the number of edges in the MST
        no_edges++;
    }

    return 0;
}
