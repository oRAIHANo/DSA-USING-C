/*

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. 
In other words, all levels are filled except possibly for the last level, which is filled from left to right.

This completeness property of complete binary trees is important for efficiently storing the elements of a heap in an array. 
Since heaps are typically represented using arrays, this property ensures that there are no "gaps" in the array representation.
Which simplifies the storage and traversal of the heap elements.

So, to clarify, when we refer to heaps as being implemented as binary trees.
We mean that they are implemented as complete binary trees.

Heap is a complete binary tree.
Heap and Binary heap both are same.
A heap is a specialized tree-based data structure that satisfies the heap property. 
It's commonly implemented as a binary tree, either as a binary min heap or a binary max heap.

*/
/*

In a heap, the elements are typically stored in an array. 
The array representation of a heap has the following characteristics:

Parent-Child Relationship:
For any node at index i:
Its left child is located at index 2i+1.
Its right child is located at index 2i+2.

Conversely, for any node at index 
Its parent is located at index [(j−1)/2].

Complete Binary Tree Property:
The elements are stored in the array in level-order traversal, meaning from left to right, top to bottom, with no gaps.
Here's a visual representation of a heap stored in an array:
          
         10
       /    \
     20     30
    /  \   /  \
   40  50 60  70

Array representation: [10, 20, 30, 40, 50, 60, 70]

Index 0: Root (10)
Index 1: Left child of the root (20)
Index 2: Right child of the root (30)
Index 3: Left child of the node at index 1 (40)
Index 4: Right child of the node at index 1 (50)
Index 5: Left child of the node at index 2 (60)
Index 6: Right child of the node at index 2 (70)

Calculating Parent, Left Child, and Right Child Indices:
Parent Index:
For any node at index j, its parent is at index 
⌊(j−1)/2⌋.

Left Child Index:
For any node at index i, its left child is at index 2i+1.
Right Child Index:
For any node at index i, its right child is at index 2i+2.

*/
/*

Types of Heaps

1) Min Heap:
In a min heap, for any given node i, the value of i is less than or equal to the values of its children.
This means that the minimum value is always at the root of the heap.
Min heaps are often used to implement priority queues, where the highest priority element (minimum value) is extracted(deleted) first.

2) Max Heap:
In a max heap, for any given node i, the value of i is greater than or equal to the values of its children.
This means that the maximum value is always at the root of the heap.
Max heaps are less common but can be used in scenarios where you need to quickly access the maximum value, such as implementing certain variations of algorithms like finding the k largest elements in a collection.

*/
/*

Operations on Heap

2) Insertion (Bottom Up approach)
When you insert a new element into a min heap.
It's typically inserted at the next available position in the array representation of the heap. 
After insertion, the heap property might be violated, so you need to perform a heapify operation to restore the heap property by swapping the newly inserted element with its parent until the heap property is satisfied.

2) Deletion (Top Down approach)
When you delete the minimum element from a min heap (which is the root).
You typically remove the root element and replace it with the last element in the heap. 
After deletion, the heap property might be violated, so you need to perform a heapify operation to restore the heap property by swapping the root with its smallest child until the heap property is satisfied.

3) Heapify is a process used to maintain the heap property in a binary heap after an insertion or deletion operation. 
It ensures that the heap property is preserved, which means that the structure of the heap remains valid and efficient for operations like extracting the minimum or maximum element.

Heapify can be performed in two ways
heapify up and heapify down
Depending on whether the operation is to restore the heap property after insertion or deletion.

1) Heapify Up (Sift-Up / Bubble-Up)
Heapify up is used after inserting an element into the heap.
In this process, the newly inserted element is swapped with its parent repeatedly until the heap property is restored.
This typically involves comparing the newly inserted element with its parent and swapping them if necessary until the parent is smaller (in a min heap) or larger (in a max heap) than the child.

2) Heapify Down (Sift-Down / Bubble-Down)
Heapify down is used after removing the root element from the heap (e.g., during extraction).
In this process, the replacement element (usually the last element in the heap) is moved down the heap by repeatedly swapping it with its smaller/larger child until the heap property is restored.
This involves comparing the replacement element with its children and swapping it with the smaller/larger child if necessary.
The process continues until either the replacement element is smaller/larger than both its children or it reaches a leaf node.

Both heapify up and heapify down operations ensure that the heap property is maintained efficiently.
Typically with a time complexity of O(logn).
Where n is the number of elements in the heap. 

*/
