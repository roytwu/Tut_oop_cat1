/* *********************************************************
File name:   main.cpp (driver program of cat.cpp, animal.cpp, and tiger.cpp)
Author:      Roy T Wu, roywu2018@gmail.com
Description: All the source files are based from "inheritance" project
********************************************************* */
#include <iostream>
#include "animal.hpp"
#include "cat.h"
#include "tiger.h"
using std::cout;
using std::endl;

int main(){
	//Animal o_am(99);  //* this won't work, instantiation is not allowed for abstract class

	cout << "*** Child class - 'Cat' ***" << endl;
	Cat *op_tom = new Cat(); 
	op_tom->m_happy = true;
	op_tom->speak(); //* Cat can do what Animal can do
	op_tom->jump();
	delete op_tom;

	cout << endl;
	Cat *op_kitty = new Cat(108);
	op_kitty->info();
	delete op_kitty;


	cout << "\n\n*** Child class - 'Tiger' ***" << endl;
	Tiger *op_bengal = new Tiger();
	op_bengal->info();
	op_bengal->speak();  //* Tiger can do what Animal can do
	op_bengal->jump();   //* Tiger can do what Cat can do
	op_bengal->attackAntelope();
	delete op_bengal;

	
	cout << "\n\n*** Polymorphism ***" << endl;
	Animal *op_animal = new Cat;  
	op_animal->speak();
	delete op_animal;


    cout << "\nEnding porgram..." <<endl;
	return 0;
}


/*
  ---------------------------------
  super-calss      Animal  
  ---------------------------------               
  sub-class          |--> Cat
  ---------------------------------
  sub-sub-class        |--> Tiger
  ---------------------------------

*/