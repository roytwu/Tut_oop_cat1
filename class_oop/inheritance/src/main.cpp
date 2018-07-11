//File name: main.cpp, 
//           driver program of cat.cpp, animal.cpp, and tiger.cpp
//Author: Roy T Wu, roywu2018@gmail.com

#include <iostream>
#include "animal.h"
#include "cat.h"
#include "tiger.h"
using std::cout;
using std::endl;

// //Return objects from functions
// Cat *createCat(){
// 	Cat *op_Cat = new Cat();
// 	op_Cat->makeAngry();
// 	return op_Cat;
// }

int main(){
	cout << "*** Super class-'Animal' ***" << endl;
	Animal o_am(99);
	o_am.speak();
	o_am.info();
	//o_am.jump(); //error!! Animal can't access its child class


	cout << endl << "*** Child class-'Cat' ***" << endl;
	Cat *op_tom = new Cat(); 
	op_tom->speak(); //Cat can do what Animal can do
	op_tom->jump();
	delete op_tom;

	cout << endl;
	Cat *op_kitty = new Cat(108);
	op_kitty->info();
	delete op_kitty;



	cout << endl << "*** Child class-'Tiger' ***" << endl;
	Tiger *op_bengal = new Tiger();
	op_bengal->info();
	op_bengal->speak();  //Tiger can do what Animal can do
	op_bengal->jump();  //Tiger can do what Cat can do
	op_bengal->attackAntelope();
	delete op_bengal;
	
	// //Test public key "happy"
	// cout << endl << "Status of Tommy kitty:" << endl;
	// o_tom.m_happy = true; 
	// o_tom.speak();
	// o_tom.jump();
	// cout << "Tommy ID: " << o_tom.getID() << endl;


    cout << endl << "Ending porgram..." <<endl;
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