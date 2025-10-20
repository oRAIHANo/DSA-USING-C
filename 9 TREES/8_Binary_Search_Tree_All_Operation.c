#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;
int value, choice;

// code to create a new node
struct node *CreateNewNode()
{
    int element;
    printf("Enter value of the new node : ");
    scanf("%d", &element);

    struct node *newnode = (struct node *)malloc(sizeof(struct node)); // creating a node pointer
    newnode->data = element;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// code to perform insertion into the tree
void Insertion(struct node *root)
{
    struct node *newnode = CreateNewNode();
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (newnode->data == root->data)
        {
            printf("Cannot insert %d, already in BST", newnode->data);
            return;
        }
        else if (newnode->data < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    if (newnode->data < prev->data)
    {
        prev->left = newnode;
    }
    else
    {
        prev->right = newnode;
    }
}

// code to perform deletion from the tree
// case 1 the node is the leaf node - search and delete
// case 2 the node is the non leaf node - search and replace it with inorder previous element or inorder post element
// case 3 the node is the root node - search and replace it with inorder previous element or inorder post element and repeat this process until the tree has no empty nodes

struct node *InOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *Deletion(struct node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    // search for the node to be deleted
    if (value < root->data)
    {
        root->left = Deletion(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = Deletion(root->right, value);
    }
    // deletion strategy
    else
    {
        // Node to be deleted is found
        // Case 1: Node with no child or one child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children
        struct node *InOrderPre = InOrderPredecessor(root);
        root->data = InOrderPre->data;
        root->left = Deletion(root->left, InOrderPre->data);
    }
    return root;
}

// code to perform pre order traversal root-left-right
void PreOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

// code to perform post order traversal left-right-root
void PostOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// code to perform in order traversal left-root-right
void InOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        InOrderTraversal(root->left);
        printf("%d ", root->data);
        InOrderTraversal(root->right);
    }
}

// code to perform recursive searching
struct node *Search(struct node *root, int value)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (value == root->data)
    {
        return root;
    }
    else if (value < root->data)
    {
        return Search(root->left, value);
    }
    else
    {
        return Search(root->right, value);
    }
}

// code to perform iterative searching
struct node *SearchIterative(struct node *root, int value)
{
    while (root != NULL)
    {
        if (value == root->data)
        {
            return root;
        }
        else if (value < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
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

    //       50
    //     /    \
    //   30     70
    //  / \    / \
    // 20 40  60 80


    printf("\nMenu\n");
    printf("Enter 1 to perform insertion into the tree\n");
    printf("Enter 2 to perform deletion from the tree\n");
    printf("Enter 3 to perform PreOrder Traversal\n");
    printf("Enter 4 to perform PostOrder Traversal\n");
    printf("Enter 5 to perform InOrder Traversal\n");
    printf("Enter 6 to perform searching\n");
    printf("Enter 7 to exit\n");
    
    while (1)
    {
        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Insertion(p);
            break;
        case 2:
            printf("Enter element that you want to delete : ");
            scanf("%d", &value);
            Deletion(p, value);
            break;
        case 3:
            printf("Pre Order Traversal : ");
            PreOrderTraversal(p);
            break;
        case 4:
            printf("Post Order Traversal : ");
            PostOrderTraversal(p);
            break;
        case 5:
            printf("In Order Traversal : ");
            InOrderTraversal(p);
            break;
        case 6:
            printf("Enter element that you want to search : ");
            scanf("%d", &value);

            struct node *n = SearchIterative(p, value);
            if (n != NULL)
            {
                printf("Element found : %d", n->data);
            }
            else
            {
                printf("Element not found");
            }
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Choice is invalid");
            break;
        }
    }

    return 0;
}