#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10
#define INF 999

int visited[MAX_NODES];
int cost[MAX_NODES][MAX_NODES];
int size;

// Example of cost matrix
// int cost[SIZE][SIZE] = {{0, 2, 0, 6, 0},
// 						   {2, 0, 3, 8, 5},
// 						   {0, 3, 0, 0, 7},
// 						   {6, 8, 0, 0, 9},
// 						   {0, 5, 7, 9, 0}};

void prims()
{
    int u, v, min, min_cost = 0, edges = 1;
    for (int i = 1; i <= size; i++)
    {
        visited[i] = 0; // Mark all nodes as unvisited
    }
    printf("Edges in MST:\n");
    visited[1] = 1; // Mark the first node as visited
    while (edges < size)
    {
        min = INF;
        for (int i = 1; i <= size; i++)
        {
            if (visited[i] == 1) // Look for visited nodes
            {
                for (int j = 1; j <= size; j++)
                {
                    if (cost[i][j] < min && visited[j] == 0) // Find the minimum cost edge
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("%d Edge (%d)(%d) = %d\n", edges++, u, v, min); // Print the selected edge
            min_cost = min_cost + min; // Update minimum cost
            visited[v] = 1; // Mark the selected node as visited
        }
        cost[u][v] = cost[v][u] = INF; // Mark the selected edge as visited
    }
    printf("\nCost of constructing MST is : %d\n", min_cost); // Print the minimum cost of MST
}

int main()
{
    printf("Enter number of nodes: ");
    scanf("%d", &size);

    printf("Enter cost matrix: \n");
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            scanf("%d", &cost[i][j]); // Input the cost matrix
            if (cost[i][j] == 0)
            {
                cost[i][j] = INF; // Assign maximum value for unconnected nodes
            }
        }
    }

    prims(); // Call the prims function
    return 0;
}

