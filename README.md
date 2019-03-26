# Learn C++
This is the repository about C++. The programs come with very verbose comments addressing concepts and syntax of C++. Most projects are developed under Linux environment, and a few are with Visual Studio.


💾 Projects
------------

## _cpp basic 
This is a dirctory including many basic concepts about C++. Projects under this direcotry are devepled under Visual Studio 2015 and CMake. It consists of the following sub-projects: 

1. **function pointer** -- beginner level example of function pointer
2. **template** -- Sample code about function templates
3. **virtual** -- Sample code about `virtual void operator()()`
4. **cmake_example** -- A good start to learn CMake
5. **pass_by_reference** -- Straightforward example of passing strings and integers by reference 
6. **inverse_a_string** -- Inverse a string with bitwise XOR `^` and `std::swap()` respectively. Also, demonstrate the difference between passing string by value and passing string by reference

## _opencv_demo
Demo of matrix operation in OpenCV
1. **basic** -- 
  This project demonstrate how to create matrices in OpenCV, and it also shows basic operations such as matrix multiplication, matrix transpose, matrix concatenation, etc.
2. **rotation** --
  This project works on roation matices and unit quaternions specifically. And it demonstrate how to convert between OpenCV and Eigen.

## eigen_demo
Using Eigen libraray for quaternion related operations

## class_oop
This is a project about implementing class in C++. 
1. **class_basic** -- Creating a class called "cat", which different cats can be named. And these cats can have different actions/mood defined as objects constructor & destructor    
2. **inheritance** -- Creat a super-class animal and its few child classes
	
## vector
The project is about how to use the vector container in C++
1. **_basic** -- Basic functions about vectors. Aslo have a example of using range-based for loop
2. **read_from_CSV** -- Reading .csv files, this project includes vectors, file stream, boost libraries, and constructor overloading
3. **unique_paths.cpp** -- a dynamic programming (DP) problem invovles using vectors

##  data_structures 
1. **binary_tree** --   Demonstrate how to build binary trees using class, and show 3 basic traversal methods in binary tree
   - pre-order: VLR  
   - in-order: LVR
   - post-order: LRV
   
2. **hash_table** -- Create hash table using <vector> and demonstrate chaining with `<list>`
	
3. **matrix_library** -- Develope a demo library for matrix operation, obsolete project   

	
## file_stream
Demonstreate how to use `<fstream>`: reading files, writing files, and parsing files  

## optional
Utilize the optional object from the Boost libaray

## operator_overloading
Illustrate basic concepts about operator overloading




🤖 Author 
------
Roy T Wu
   
    

📚 Ackowledgements
---------------
- https://caveofprogramming.teachable.com/p/c-beginners  
- http://alrightchiu.github.io/SecondRound/
- LeetCode - unique paths
- C++ Primer (5th edition) ISBN-10: 0321714113
