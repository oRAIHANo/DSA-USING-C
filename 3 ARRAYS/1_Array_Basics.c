/*

what is array?
An array is a data structure that stores a collection of elements, typically of the same type, in contiguous memory locations. 
Each element in the array is accessed by its index, which is a numerical value indicating its position in the array. 
Arrays are fundamental in programming and are used for organizing and manipulating data efficiently. 
They provide a way to store multiple values of the same data type under a single name.

Syntax - int array[5] = {1,2,3,4,5};

How to calculate the size of the array?
int array[5] = {1,2,3,4,5};
int size = sizeof(array) / sizeof(array[0]);

Types of arrays?
1) One-dimensional Array
This is the simplest form of an array, where elements are arranged in a single row or column.

2) Multi-dimensional Array
These arrays have more than one dimension. For example, a two-dimensional array can be thought of as a grid with rows and columns, and a three-dimensional array can be visualized as a cube with layers.

3) Fixed-size Array
In these arrays, the size is predetermined and cannot be changed once the array is created.

4) Dynamic Array
Dynamic arrays can resize themselves dynamically during program execution. 
This flexibility comes at the cost of slightly more overhead compared to fixed-size arrays.

5) Sparse Array
In a sparse array, most of the elements have the value of a specified default value (typically zero or null).
Rather than explicitly storing every element.

6) Jagged Array
A jagged array is an array of arrays where each element can be of different sizes. 
This is useful when you need arrays of varying lengths.

7) String Array 
An array where each element is a string. 
This is commonly used to store lists of strings or text data.

8) Boolean Array
An array where each element is a boolean value, representing true or false.

9) Character Array (String)
An array where each element is a character. 
These are often used to represent strings of text in programming languages that don't have a dedicated string data type like in c.

10) Object Array
An array where each element is an object of a certain class or data structure. 
This allows for storing complex data structures in an array format.



*/