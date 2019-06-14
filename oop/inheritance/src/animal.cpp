/* *********************************************************
File name:   animal.cpp (_inheritance)
Programmer:  Roy Wu
Description: super class
********************************************************* */
#include <iostream>
#include "animal.h"
#include "cat.h"

//* no-argument constructor
Animal::Animal(){
	int m_animalID =0;
	cout << "  --Animal no-argument consructor called--" << endl;
}

//* parameterized constructor
Animal::Animal(int m_animalID){
	this->m_animalID = m_animalID;
	cout << "  --Animal parameterized consructor called--" << endl;
}

//* destructor
Animal::~Animal(){}	


void Animal::speak(){ 
	cout << "  Grrrrr...(animal speaking)" << endl; 
}

void Animal::info(){ 
	cout << "  animalID is ... " << m_animalID << endl; 
}
