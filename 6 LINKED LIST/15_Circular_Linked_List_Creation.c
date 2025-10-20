#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node *head, *second, *third, *fourth, *fifth;

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
    /* The only difference between a singly linked list and a circular linked list is that the last node in a singly linked list points to NULL.
    Whereas in a circular linked list, the last node points back to the first node instead of NULL. */
    fifth->link = head;

    printf("%d\n",head->data);
    printf("%d\n",second->data);
    printf("%d\n",third->data);
    printf("%d\n",fourth->data);
    printf("%d\n",fifth->data);
    printf("%d", fifth->link->data);
}

