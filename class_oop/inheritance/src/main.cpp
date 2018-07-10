//File name: main.cpp, 
//           driver program of cat.cpp, animal.h
//Author: Roy T Wu, roywu2018@gmail.com

#include <iostream>
#include "cat.h"
#include "animal.h"
using std::cout;
using std::endl;

//Return objects from functions
// Cat *createCat(){
// 	Cat *op_Cat = new Cat();
// 	op_Cat->makeAngry();
// 	return op_Cat;
// }

int main(){

	Animal o_am;
	o_am.speak();

	Cat o_tom; 
	o_tom.speak();
	
	// //Test public key "happy"
	// cout << endl << "Status of Tommy kitty:" << endl;
	// o_tom.m_happy = true; 
	// o_tom.speak();
	// o_tom.jump();
	// cout << "Tommy ID: " << o_tom.getID() << endl;

	// // use "new" operator
	// cout << endl << endl;
	// Cat *op_john = new Cat();
	// (*op_john).jump();  //dereference the pointer first to get the object,
	// op_john -> speak(); //this is same as (*pJohn).speak()
	// delete op_john;     

    cout << endl << "Ending porgram..." <<endl;
	return 0;
}