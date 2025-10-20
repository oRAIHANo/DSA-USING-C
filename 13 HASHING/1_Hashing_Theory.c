/*

Hashing in Data Structure?
Hashing is a technique used in data structures to store and retrieve data efficiently. 
It involves using a hash function to map data items to a fixed-size array which is called a hash table.
Hashing is a fundamental data structure that efficiently stores and retrieves data in a way that allows for quick access. 
It involves mapping data to a specific index in a hash table using a hash function that enabling fast retrieval of information based on its key. 
This method is commonly used in databases, caching systems, and various programming applications to optimize search and retrieval operations.

Hash Table in Data Structure?
A hash table is also known as a hash map. 
It is a data structure that stores key-value pairs. 
It uses a hash function to map keys to a fixed-size array, called a hash table. This allows in faster search, insertion, and deletion operations.

Hash Function?
It is a mathematical function formula used to map a given key within hash table.
The hash function is used to find the index of the array. 
The hash value is used to create an index for the key in the hash table. 
The hash function is a function that takes a key and returns an index into the hash table. 

The goal of a hash function is to distribute keys evenly across the hash table, minimizing collisions (when two keys map to the same index).

Types of hash functions?
1) Division Method
Key % Hash Table Size
h(k) = k mod m
h(k) = k % m 
h(k) = address in hash table
k = key to be stored
m = size of hash table
example
if m = 5 and k = 20,21,22,23
h(20) = 20 mod 5 = 0, index value of 20 in hash table is 0
h(21) = 21 mod 5 = 1, index value of 21 in hash table is 1
h(22) = 22 mod 5 = 2, index value of 22 in hash table is 2
h(23) = 23 mod 5 = 3, index value of 23 in hash table is 3
hash table
| Index | Value |
|  0    |  20   |
|  1    |  21   |
|  2    |  22   |
|  3    |  23   |

2) Mid Square Method
example
if k = 25
k^2 = 625
Remove left and right most value from the k^2 and value at centre is the index of the element. 
In this case k is 25 and k^2 is 625, after removing the left and right most value which is 6 and 5.
We got 2 as the index of the element.
If k^2 = 6024 the index is 0. Remove 1 value from the left and 2 values from the right

3) Folding Method
example
if k = 123456 and hash table index values are from 0 to 999
then fold your value into two parts and perfrom add operation
   123
+  456
   ___
   579
Storing 123456 is not possible as index of hash table is from 0 to 999 or you can say due to the limited size of the hash table.
But after performing folding operation the we were able to the solve the problem of indexing.
Now we can store value 123456 at index number 579 in hash table

why do we need hashing in data structure?
Hashing is a fundamental concept in computer science and data structures for several reasons:
1) Fast Retrieval
Hashing enables quick retrieval of data from a collection. 
Instead of searching through the entire collection linearly, which could be time-consuming for large datasets, hashing allows for constant-time (O(1)) retrieval of elements.

2)Efficient Storage
Hashing allows for efficient storage of data by mapping keys to indices in an array. 
This can significantly reduce memory usage compared to other data structures like trees or linked lists.

3) Data Integrity and Security
Hash functions are widely used in cryptography and security applications to ensure data integrity and authentication. 
By generating a fixed-size hash value for a given input (data), hash functions enable verification of data integrity and help in detecting tampering or corruption.

4) Reducing Collisions
While collisions (two different keys mapping to the same hash value) can occur in hashing, various techniques such as chaining or open addressing are employed to handle them efficiently. 
When collisions are minimized, the efficiency of data retrieval remains high.

5) Distributed Systems
In distributed systems, hashing is often used for load balancing and data partitioning. 
Hashing allows for distributing data across multiple nodes or servers based on the hash value of keys, ensuring that data is evenly distributed and accessible.

Collision in Hashing?
In this, the hash function is used to find the index of the array. 
The hash value is used to create an index for the key in the hash table. 
The hash function may return the same hash value for two or more keys. 
When two or more keys have the same hash value, a collision happens.
example
if m = 5 and k = 20,21,22,23, 32
h(20) = 20 mod 5 = 0, index value of 20 in hash table is 0
h(21) = 21 mod 5 = 1, index value of 21 in hash table is 1
h(22) = 22 mod 5 = 2, index value of 22 in hash table is 2
h(23) = 23 mod 5 = 3, index value of 23 in hash table is 3
h(32) = 32 mod 5 = 2, index value of 32 in hash table is 2
hash table
| Index | Value |
|  0    |  20   |
|  1    |  21   |
|  2    |  22   |
|  3    |  23   |
There is a collision between 22 and 32 as the index of both the keys is 2.
We cannot put 32 at address 2 as it is already occupied.

Collision Resolution Techniques?
There are two types of collision resolution techniques.
Separate chaining (open hashing)
Open addressing (closed hashing)

*/