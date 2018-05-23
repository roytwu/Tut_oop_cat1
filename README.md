# tut_oop_cat1
OOP tutorial: cat1

This is a tutorial program about Class in C++ targeting beginners
Creating a class called "cat", which different cats can be named
these cats can have different actions/mood defined as objects

Original code is from the Udemy online course:　C++ Tutorial for Complete Beginners offered by John Purcell

C++ files:    main.cpp cat.cpp
hader files:  cat.h
executables:  class_exe
Makefile


constructor & desstructor
1. Constructor is not necessary if in-class initialization is applied
2. There are two ways of defining constructor:
	A. In cat.h, under public key, type: Cat(); 
	   In cat.cpp, write a constructor function Cat::Cat(){...}
	B. In cat.h, under public key, type: Cat():...{}