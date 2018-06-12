/* 
main file for cat.cpp and cat.h
Structure of class "Cat" is defined in cat.h; functions of "Cat" are defined in cat.cpp
In this program, name different cats like "tom", "nancy"
*/
//File name: main.cpp
//Programmer: TWu

#include <iostream>
#include "cat.h"
using std::cout;
using std::endl;

//Return objects from functions
Cat *createCat(){
	Cat *pCat = new Cat();
	pCat -> makeAngry();
	return pCat;
	/*when we return a pointer, we return a copy of pointer, however;
	this is just copyng a 8 bite memory address, so... 
	even "Cat" contains mega bytes of data, this operation will still be memory efficient 
	*/
}

int main(){
	Cat tom, nancy, bob; //define objects within class "Cat"
	
	//Test public key "happy"
	cout << endl << "Status of Tommy kitty:" << endl;
	tom.happy = true; 
	tom.speak();
	tom.jump();
	cout << "Tommy ID: " << tom.getID() << endl;

	cout << endl << "Status of Nancy kitty:" << endl;
	nancy.happy = false;
	nancy.speak();

	//Test private key "angry", which is a better coding practice
	cout << endl << "Status of Bobby kitty:" << endl;
	bob.makeAngry();
	bob.speak();

	// use "new" operator
	cout << endl << endl;
	Cat *pJohn = new Cat();
	(*pJohn).jump();  //dereference the pointer first to get the object,
	pJohn -> speak(); //this is same as (*pJohn).speak()
	delete pJohn;     //whenever "new" is called, "delete" shall be called as well 

    cout << endl << endl;
    // Return objets from functions 
    Cat *pEmma = createCat();
    pEmma -> speak();
    cout << "Emma's ID: " << pEmma -> getID() << endl;
    delete pEmma;

    //We don't need an object to access the static varaible,
    //since static varialbe is associated with the class, not with an object 
    cout << endl << "Static Variable: " << endl;
    cout << Cat::MAX << endl;


    cout << endl << "Ending porgram..." <<endl;
	return 0;
}