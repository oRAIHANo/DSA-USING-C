#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL, *second, *third, *fourth, *fifth, *ptr;
int element;

// code for linked list searching
void LinkedListSearch()
{
    printf("Enter element that you want to search : ");
    scanf("%d", &element);
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data != element)
        {
            printf("Element found");
        }
        ptr = ptr->link;
    }
}

// code for linked list traversal
void LinkedListTraversal()
{
    if (head == NULL)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        int i = 0;
        ptr = head;
        while (ptr != NULL)
        {
            i++;
            printf("Element %d : %d\n", i, ptr->data);
            ptr = ptr->link;
        }
    }
}

void main()
{
    // Allocate memory for nodes in the linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;
    fifth->data = 50;

    head->link = second;
    second->link = third;
    third->link = fourth;
    fourth->link = fifth;
    fifth->link = NULL;

    LinkedListTraversal(head);
    LinkedListSearch(head);
}