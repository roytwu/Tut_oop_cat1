/* *********************************************************
File name:   animal.cpp (_inheritance)
Author:      Roy Wu
Description: super class
********************************************************* */
#include <iostream>
#include "animal.h"
#include "cat.h"

//* no-argument constructor
Animal::Animal(){
	int m_animalID =0;
	cout << "\t--Animal no-argument consructor called--" << endl;
}

//* parameterized constructor
Animal::Animal(int m_animalID)
{
	this->m_animalID = m_animalID;
	cout << "\t--Animal parameterized consructor called--" << endl;
}

//* destructor
Animal::~Animal()
{
	cout << "*Destructor (Animal) is called...\n";
}	


void Animal::speak(){ 
	cout << "\tGrrrrr...(animal speaking)" << endl; 
}

void Animal::info(){ 
	cout << "\tanimalID is ... " << m_animalID << endl; 
}
