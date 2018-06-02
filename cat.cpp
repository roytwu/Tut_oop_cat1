//File name: cat.cpp
//Programmer: TWu

#include <iostream>
#include "cat.h"
using std::cout;
using std::endl;


int Cat::countObject = 0;

Cat::Cat() //consructor function
{
	/*3rd way to initialize variable angry*/
	cout << "Cat consructor called, program created!" <<endl;
	angry = false;
	id = ++countObject;  //prefix increment
}


Cat::~Cat() //destructor function
{
	cout << "Cat desructor called. Cat destroyed." <<endl;
}


void Cat::makeAngry(){
	angry = true;
}

void Cat::makeSad(){
	angry = false;
}

void Cat::speak(){
	if(happy){
		cout << "Meouww! kitty is happy!" << endl;	
	} 
	else if(angry){
		cout << "krrr!! Fuck off!" << endl;
	}
	else{
		cout << "Ssssss..." << endl;
	}
}

void Cat::jump(){
	cout << "Jumping into muddy puddle!" << endl;
}


int Cat::getID(){
	return id;
}



