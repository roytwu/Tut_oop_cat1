/* 
main file for cat.cpp and cat.h
Structure of class "Cat" is defined in cat.h; functions of "Cat" are defined in cat.cpp
In this program, name different cats like "tom", "nancy"
*/
//File name: main.cpp
//Author: Roy T Wu, roywu2018@gmail.com

#include <iostream>
#include "cat.h"
using std::cout;
using std::endl;

//Return objects from functions
Cat *createCat(){
	Cat *op_Cat = new Cat();
	op_Cat->makeAngry();
	return op_Cat;
	/*when we return a pointer, we return a copy of pointer, however;
	this is just copyng a 8 bite memory address, so... 
	even "Cat" contains mega bytes of data, this operation will still be memory efficient 
	*/
}

int main(){
	Cat o_tom, o_nancy, o_bob; //define objects within class "Cat"
	
	//Test public key "happy"
	cout << endl << "Status of Tommy kitty:" << endl;
	o_tom.m_happy = true; 
	o_tom.speak();
	o_tom.jump();
	cout << "Tommy ID: " << o_tom.getID() << endl;

	cout << endl << "Status of Nancy kitty:" << endl;
	o_nancy.m_happy = false;
	o_nancy.speak();

	//Test private key "angry", which is a better coding practice
	cout << endl << "Status of Bobby kitty:" << endl;
	o_bob.makeAngry();
	o_bob.speak();

	// use "new" operator
	cout << endl << endl;
	Cat *op_john = new Cat();
	(*op_john).jump();  //dereference the pointer first to get the object,
	op_john -> speak(); //this is same as (*pJohn).speak()
	delete op_john;     //whenever "new" is called, "delete" shall be called as well 

    cout << endl << endl;
    // Return objets from functions 
    Cat *op_emma = createCat();
    op_emma -> speak();
    cout << "Emma's ID: " << op_emma->getID() << endl;
    delete op_emma;

    //We don't need an object to access the static varaible,
    //since static varialbe is associated with the class, not with an object 
    cout << endl << "Static Variable: " << endl;
    cout << Cat::MAX << endl;


    cout << endl << "Ending porgram..." <<endl;
	return 0;
}