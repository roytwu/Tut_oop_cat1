/* 
main file for cat.cpp and cat.h
The structure of class "Cat" is defined in cat.h
and the functions of "Cat" are defined in cat.cpp

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
		this is just copyng a 8 bite memory address, 
		so even the "Cat" contains of mega bytes of data, 
		this kind of operation will still be memory efficient 
	*/
}

int main(){
	Cat tom, nancy, bob; //define objects within class "Cat"
	
	//Test public key "happy"
	cout << "Status of Tommy kitty:" << endl;
	tom.happy = true; 
	tom.speak();
	tom.jump();
	cout << endl;

	cout << "Status of Nancy kitty:" << endl;
	nancy.happy = false;
	nancy.speak();
	cout << endl;

	//Test private key "angry", which is a better coding practice
	cout << "Status of Bobby kitty:" << endl;
	bob.makeAngry();
	bob.speak();

	// use "new" operator
	cout << endl << endl;
	Cat *pJohn = new Cat();
	(*pJohn).jump(); //dereference the pointer first to get the object,
	pJohn -> speak(); //this is same as (*pJohn).speak()
	delete pJohn;   //whenever "new" is called, "delete" shall be called as well 

    cout << endl << endl;
    // Return objets from functions 
    Cat *pEmma = createCat();
    pEmma -> speak();
    delete pEmma;


    cout << endl << "Ending porgram..." <<endl;
	return 0;
}