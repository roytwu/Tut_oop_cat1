//File name: cat.cpp
//Programmer: TWu

#include <iostream>
#include "cat.h"
using std::cout;
using std::endl;

//static variables can't be initialized in the class, so, 
//it's common practive to initialize static variable in cpp file
int Cat::countObject = 0;

Cat::Cat() //consructor function
{
	/*3rd way to initialize variable angry*/
	cout << "Cat consructor called, program created!" << endl;
	m_angry = false;
	m_id = ++countObject;  //prefix increment
}


Cat::~Cat() //destructor function
{
	cout << "Cat desructor called. Cat destroyed." << endl;
}


void Cat::makeAngry(){
	m_angry = true;
}

void Cat::makeSad(){
	m_angry = false;
}

void Cat::speak(){
	if(m_happy){
		cout << "Meouww! kitty is happy!" << endl;	
	} 
	else if(m_angry){
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
	return m_id;
}



