#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prevlink;
    struct node *nextlink;
};

// code for linked list traversal
void LinkedListTraversal(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->nextlink;
    }
}

// code for linked list traversal in reverse order
void LinkedListTraversalReverse(struct node *fifth)
{
    struct node *ptr = fifth;
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->prevlink;
    }
}

int main()
{
    // Allocate memory for nodes in the linked list in heap
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    struct node *fifth = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;
    fifth->data = 50;

    head->prevlink = NULL;
    second->prevlink = head;
    third->prevlink = second;
    fourth->prevlink = third;
    fifth->prevlink = fourth;

    head->nextlink = second;
    second->nextlink = third;
    third->nextlink = fourth;
    fourth->nextlink = fifth;
    fifth->nextlink = NULL;

    printf("Linked List Traversal in normal order\n");
    LinkedListTraversal(head);
    printf("Linked List Traversal in reverse order\n");
    LinkedListTraversalReverse(fifth);

    return 0;
}