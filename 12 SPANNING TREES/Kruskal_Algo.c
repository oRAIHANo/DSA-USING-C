#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

// Comparator function for sorting edges
int comparator(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    return x[2] - y[2];
}
   
// Function to find the parent of a vertex (with path compression)
int findParent(int parent[], int vertex)
{
    if (parent[vertex] == -1)
        return vertex;
    return parent[vertex] = findParent(parent, parent[vertex]);
}

// Function to perform union of two sets
void unionSet(int parent[], int x, int y)
{
    int xSet = findParent(parent, x);
    int ySet = findParent(parent, y);
    parent[xSet] = ySet;
}

// Function to find the Minimum Spanning Tree (MST) using Kruskal's algorithm
void kruskalMST(int numVertices, int numEdges, int edges[][3])
{
    int parent[MAX_VERTICES];
    for (int i = 0; i < numVertices; i++)
        parent[i] = -1;

    qsort(edges, numEdges, sizeof(edges[0]), comparator);

    printf("Following are the edges in the constructed MST:\n");
    int minCost = 0;
    for (int i = 0; i < numEdges; i++)
    {
        int x = findParent(parent, edges[i][0]);
        int y = findParent(parent, edges[i][1]);
        if (x != y)
        {
            printf("%d -- %d == %d\n", edges[i][0], edges[i][1], edges[i][2]);
            minCost += edges[i][2];
            unionSet(parent, x, y);
        }
    }
    printf("Minimum Cost Spanning Tree: %d\n", minCost);
}

// Main function
int main()
{
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    int edges[MAX_EDGES][3];
    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < numEdges; i++)
    {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    kruskalMST(numVertices, numEdges, edges);

    return 0;
}
