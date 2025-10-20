// DFS uses stack for implementation
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int visited[SIZE];
int choice;

// Example adjacency matrix representation (replace with your own)
// int adj[SIZE][SIZE] = {{0, 1, 1, 1, 0},
//                        {0, 0, 0, 1, 0},
//                        {0, 1, 0, 0, 0},
//                        {0, 0, 0, 0, 1},
//                        {0, 0, 1, 0, 0}};
int adj[SIZE][SIZE] = {}; // Example adjacency matrix representation

// Breadth-First Search function
void DepthFirstSearch(int i)
{
    printf("%c ", i + 65);
    visited[i] = 1;
    for (int j = 0; j < SIZE; j++)
    {
        if (adj[i][j] == 1 & !visited[j])
        {
            DepthFirstSearch(j);
        }
    }
}

int main()
{
    while (1)
    {
        printf("\nMenu\n");
        printf("1. Enter values into the graph\n");
        printf("2. DFS traversal\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the adjacency matrix:\n");
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    scanf("%d", &adj[i][j]);
                }
            }
            break;
        case 2:
            printf("Depth First Search Traversal : ");
            DepthFirstSearch(0);
            break;
        case 3:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}
