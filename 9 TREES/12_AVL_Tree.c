/*

An AVL tree, also known as Adelson-Velsky and Landis tree, is a self-balancing binary search tree in computer science. 
In this data structure, the heights of two child subtrees of any node differ by a maximum of one.
The difference between the heights of the left subtree and the right subtree for any node is known as the balance factor of the node.
Balance factor = Height of left subtree - Height of right subtree
Balance factor can be -1,0,1 for a node to be balanced in Binary search tree
Balance factor can be -1,0,1 for all node of an AVL tree

Applications of AVL Tree
It is used to index huge records in a database and also to efficiently search in that.
For all types of in-memory collections, including sets and dictionaries, AVL Trees are used.
Database applications, where insertions and deletions are less common but frequent data lookups are necessary
Software that needs optimized search.
It is applied in corporate areas and storyline games.

Advantages of AVL Tree
AVL trees can self-balance themselves.
It is surely not skewed.
It provides faster lookups than Red-Black Trees
Better searching time complexity compared to other trees like binary tree.
Height cannot exceed log(N), where, N is the total number of nodes in the tree.

Disadvantages of AVL Tree
It is difficult to implement.
It has high constant factors for some of the operations.
Less used compared to Red-Black trees.
Due to its rather strict balance, AVL trees provide complicated insertion and removal operations as more rotations are performed.
Take more processing for balancing.

AVL Tree rotation operation
Types of rotaion in AVL tree LL, LR, Rl, RR
We can perform operation to balance a binary search tree such that the newly formed tree satisfies all the properties of a BST.
In order to balance an AVL tree after insertion we can follow the following rules
For a Left Left rotation - Right rotate once wrt to first imbalanced node
For a Right Right rotation - Left rotate once wrt to first imbalanced node
For a Left Right rotation - Left rotate the child of first imbalanced node and then right rotate the first imbalanced node
For a Right Left rotation - Right rotate the child of first imbalanced node and then left rotate the first imbalanced node

*/


