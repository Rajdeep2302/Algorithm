#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct
{
    int u, v, weight;
} Edge;
int parent[MAX];
int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}
int union_set(int i, int j)
{
    int a = find(i);
    int b = find(j);
    if (a != b)
    {
        parent[b] = a;
        return 1;
    }
    return 0;
}
int main()
{
    int n, e;
    Edge edges[MAX];
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &edges[i].u,
              &edges[i].v, &edges[i].weight);
    }
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
    int total = 0;
    printf("Edge : Weight\n");
    for (int i = 0; i < e; i++)
    {
        if (union_set(edges[i].u, edges[i].v))
        {
            printf("%d - %d : %d\n", edges[i].u,
                   edges[i].v, edges[i].weight);
            total += edges[i].weight;
        }
    }
    printf("Total cost: %d\n", total);
    return 0;
}