// BFS is a level order traversal and uses queue for implementation
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int visited[SIZE];         // Array to mark visited vertices
int explored_queue[SIZE];  // Queue for BFS traversal
int rear = -1, front = -1; // Pointers for the queue
int choice;

// Example adjacency matrix representation (replace with your own)
// int adj[SIZE][SIZE] = {{0, 1, 1, 1, 0},
//                        {0, 0, 0, 1, 0},
//                        {0, 1, 0, 0, 0},
//                        {0, 0, 0, 0, 1},
//                        {0, 0, 1, 0, 0}};
int adj[SIZE][SIZE] = {}; // Example adjacency matrix representation

int IsEmpty()
{
    if (front == -1)
    {
        return 1; // Queue is empty
    }
    return 0;
}

int IsFull()
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        return 1; // Queue is full
    }
    return 0;
}

void EnQueue(int vertex)
{
    if (IsFull())
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
            /*If queue is initially empty */
            front = 0;

        rear = rear + 1;
        explored_queue[rear] = vertex;
    }
}

int DeQueue()
{
    if (IsEmpty())
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        int item = explored_queue[front];
        if (front == rear)
        {
            front = rear = -1; // Reset the queue when it becomes empty
        }
        else
        {
            front++;
        }
        return item;
    }
}

// Breadth-First Search function
void BreadthFirstSearch(int start)
{
    // Initialize visited array
    for (int k = 0; k < SIZE; k++)
        visited[k] = 0;

    // Enqueue the starting vertex
    EnQueue(start);
    visited[start] = 1;

    // BFS traversal
    while (!IsEmpty())
    { // Explored queue is not empty
        // Dequeue a vertex
        int current_vertex = DeQueue();
        printf("%c ", current_vertex + 65); // Assuming vertices are represented as characters

        // Enqueue unvisited neighbors
        for (int i = 0; i < SIZE; i++)
        {
            if (adj[current_vertex][i] && visited[i] == 0)
            {                   // If there's an edge and the neighbor is not visited
                EnQueue(i);     // Enqueue the neighbor
                visited[i] = 1; // Mark the neighbor as visited
            }
        }
    }
}

int main()
{
    while (1)
    {
        printf("\nMenu\n");
        printf("1. Enter values into the graph\n");
        printf("2. BFS traversal\n");
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
            printf("Breadth First Search Traversal : ");
            BreadthFirstSearch(0);
            break;
        case 3:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}
