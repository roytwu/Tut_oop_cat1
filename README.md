# Learn C++
This is the repository about C++. The programs come with very verbose comments addressing concepts and syntax of C++.


💾 Projects
------------

## 1. class_oop
This is a project about implementing class in C++. 

- ### 1-a. class_basic
  Creating a class called "cat", which different cats can be named
  And these cats can have different actions/mood defined as objects
  constructor & destructor
  1. Constructor is not necessary if in-class initialization is applied
  2. There are two ways of defining constructor:   
    - In cat.h, under public key, type: `Cat()`; 
      In cat.cpp, write a constructor function `Cat::Cat(){...}`      
    - In cat.h, under public key, type: `Cat():...{}`
   
 - ### 1-b. inheritance
 Creat a super-class animal and its few childe classes
	
## 2. vector
The project is about how to use vector container in C++
- **vector_basic.cpp**: basic commands about vectors  
- **unique_paths.cpp**: a dynamic programming (DP) problem invovles using vectors


## 3. inverse_a_string
Inverse a string with bitwise XOR `^` and `std::swap()` respectively. Also, demonstrate the difference between passing string by value and passing string by reference


## 4. binary_tree
Demonstrate how to build binary trees using class, and show 3 basic traversal methods in binary tree
- pre-order: VLR  
- in-order: LVR
- post-order: LRV


## 5. hash_table
Create hash table using <vector> and demonstrate chaining with `<list>`
	
	
## 6. file
Demonstreate how to use `<fstream>`: reading files, writing files, and parsing files  



## matrix_library
Develope a demo library for matrix operation, obsolete project     
   

🤖 Author 
------
Roy T Wu
   
    

📚 Ackowledgements
---------------
- https://caveofprogramming.teachable.com/p/c-beginners  
- http://alrightchiu.github.io/SecondRound/
- LeetCode - unique paths
- C++ Primer (5th edition) ISBN-10: 0321714113
