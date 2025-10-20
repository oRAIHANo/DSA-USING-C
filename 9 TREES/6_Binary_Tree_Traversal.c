#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *CreateNewNode()
{
    int value;
    struct node *newnode = (struct node *)malloc(sizeof(struct node)); // creating a node pointer
    printf("Enter value of the newnode : ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void PreOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void PostOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void InOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        InOrderTraversal(root->left);
        printf("%d ", root->data);
        InOrderTraversal(root->right);
    }
}

int main()
{
    struct node *p = CreateNewNode();
    struct node *p1 = CreateNewNode();
    struct node *p2 = CreateNewNode();
    struct node *p3 = CreateNewNode();
    struct node *p4 = CreateNewNode();
    struct node *p5 = CreateNewNode();
    struct node *p6 = CreateNewNode();

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    //        p
    //     /    \
    //   p1     p2
    //  / \    / \
    // p3 p4  p5 p6

    //        1
    //     /    \
    //   2      3
    //  / \    / \
    // 4  5   6  7

    printf("Pre Order Traversal : ");
    PreOrderTraversal(p);
    printf("\n");
    printf("Post Order Traversal : ");
    PostOrderTraversal(p);
    printf("\n");
    printf("In Order Traversal : ");
    InOrderTraversal(p);

    return 0;
}
