# C++ Overview
This is the repository about C++ and related open source libaries such as OpenCV and Eigen. The programs come with very verbose comments to address concepts and syntax of C++. Most projects are developed under Visual Studio and a few are developed under Linux GCC.


💾 Projects
------------

## _cpp basic 
This is a dirctory including many basic concepts about C++. Projects under this direcotry are devepled under Visual Studio 2015 and CMake. It consists of the following sub-projects: 

1. **algorithm** -- Demo about functions in `<algorithm>`   
2. **cmake_example** -- A good start to learn CMake   
3. **enum** -- scoped and unscoped enumeration  
4. **file_stream** -- Demonstreate how to use `<fstream>`: reading files, writing files, and parsing files  
5. **function pointer** -- beginner level example of function pointer  
6. **inverse_a_string** -- Inverse a string with bitwise XOR `^` and `std::swap()` respectively. Also, demonstrate the difference   between passing string by value and passing string by reference  
7. **pass_by_reference** -- Straightforward example of passing strings and integers by reference  
8. **template** -- Sample code about function templates
9. **virtual** -- Sample code about `virtual void operator()()` 

## _opencv_demo
Demo of matrix operation in OpenCV
1. **basic** -- 
  This project demonstrate how to create matrices and vectors in OpenCV, it also shows basic operations such as matrix multiplication, matrix transpose, matrix concatenation, inner product and cross product between 2 vectors, etc.
2. **rotation** --
  This project works on roation matices and unit quaternions specifically. And it demonstrate how to convert between OpenCV and Eigen.
3. **quaternion** --
  Handles unit quaternion opeations and mapping between SO(3) and S(3)
4. **imageStacking** --
  Noise removal by image averaging
   
  

## _vtk
Impplemented the Visualization Toolkit (VTK) in C++. The following projects are included: 
1. **basic** -- The most baisc implementation of VTK
2. **axes**  -- Creating a coordinate frame with 3 orthogoal axes
3. **cubic** -- Creating a cubic
4. **grid**  -- Creating grids in XY amd XZ plan

## eigen_demo
Using Eigen libraray for quaternion related operations

## oop
This is a project about implementing class in C++. 
1. **class_basic** -- Creat a class called "cat", which different cats can be named. And these cats can have different actions/mood defined as objects constructor & destructor    
2. **inheritance** -- Creat a super-class animal and its few child classes
3. **static** -- illustrtate the use of static memebers of class
4. **virtual_function** --  basic concepts of polymorphism
	
## vector
The project is about how to use the vector container in C++
1. **_basic** -- Basic functions about vectors. Aslo have a example of using range-based for loop
2. **read_from_CSV** -- Reading .csv files, this project includes vectors, file stream, boost libraries, and constructor overloading
3. **unique_paths.cpp** -- a dynamic programming (DP) problem invovles using vectors

## operator_overloading
Illustrate basic concepts about operator overloading

## generic_programming
Generic Programming enables the programmer to write a general algorithm which will work with all data types, and it can be implemented in C++ using templates
1. **class_template** -- examples of class template
2. **func_template** --  examples of function template

##  data_structures 
1. **binary_tree** --   Demonstrate how to build binary trees using class, and show 3 basic traversal methods in binary tree
   - pre-order: VLR  
   - in-order: LVR
   - post-order: LRV
   
2. **hash_table** -- Create hash table using <vector> and demonstrate chaining with `<list>`
	
3. **matrix_library** -- Develope a demo library for matrix operation, obsolete project   

## optional
Utilize the optional object from the Boost libaray




🤖 Developer 
------
Roy T Wu
   
    

📚 Ackowledgements
---------------
- https://caveofprogramming.teachable.com/p/c-beginners  
- http://alrightchiu.github.io/SecondRound/
- LeetCode - unique paths
- C++ Primer (5th edition) ISBN-10: 0321714113
- https://vtk.org/Wiki/VTK/Examples/Cxx
