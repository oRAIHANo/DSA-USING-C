/*

Binary Tree is also known as tree of degree 2.

Binary Tree can have atmost 2 children. Nodes can have 0, 1 or 2 children.

Types of Binary Tree

Full or Strict Binary trees
Binary trees as we said earlier have a degree of 2 or less than 2.
But a strict binary tree is a binary tree having all of its nodes with a degree of 2 or 0.
That is each of its nodes either have 2 children or is a leaf node.

Perfect Binary Tree
A perfect binary tree has all its internal nodes with degree strictly 2 and has all its leaf nodes on the same level.
A perfect binary tree as the name suggests appears exactly perfect.

Complete Binary Tree
A complete binary tree has all its levels completely filled except possibly the last level.
And if the last level is not completely filled then the last level’s keys must be all left-aligned.

Degenerate tree
The easiest of all, degenerate trees are binary trees where every parent node has just one child and that can be either to its left or right.

Type of Degenerate tree - Skewed trees
Skewed trees are binary trees where every parent node has just a single child and that child should be strict to the left or to the right for all the parents.
Slewed trees having all the child nodes aligned to the left are called left-skewed trees, and skewed trees having all the child nodes aligned to the right are called right-skewed trees.

Representation of a Binary Tree
Array representation of Binary trees
Arrays are linear data structures and for arrays to function, their size must be specified before elements are inserted into them.
And this counts as the biggest demerit of representing binary trees using arrays.
Suppose you declare an array of size 100, and after storing 100 nodes in it, you cannot even insert a single element further, regardless of all the spaces left in the memory.
Another way you’d say is to copy the whole thing again to a new array of bigger size but that is not considered a good practice.

Linked Representation of Binary Trees

This method of representing binary trees using linked nodes is considered the most efficient method of representation.
For this, we use doubly-linked lists

*/

// Representation of a Binary Tree do it yourself
// Linked Representation of Binary Trees

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

int main()
{
    struct node *p = CreateNewNode();
    struct node *p1 = CreateNewNode();
    struct node *p2 = CreateNewNode();

    p->left = p1;
    p->right = p2;

    //        p
    //     /    \
    //   p1     p2

    //        1
    //     /    \
    //   2      3

    return 0;
}
