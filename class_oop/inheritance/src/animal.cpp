//File name: animal.cpp
//Programmer: Roy TWu


#include <iostream>
#include "animal.h"
#include "cat.h"
using std::cout;
using std::endl;

//no-argument constructor
Animal::Animal(){
	int m_animalID =0;
	cout << " --Animal no-argument consructor called--" << endl;
}

//parameterized constructor
Animal::Animal(int m_animalID){
	this->m_animalID = m_animalID;
	cout << " --Animal parameterized consructor called--" << endl;
}

	
void Animal::speak(){ 
	cout << " Grrrrr...." << endl; 
}

void Animal::info(){ 
	cout << " animalID is ... " << m_animalID << endl; 
}
