#include <iostream>
#include "cat.h"

//static variables can't be initialized in the class, so, 
//it's common practive to initialize static variable in cpp file
int Cat::countObject = 0;

Cat::Cat() //consructor function
{
	m_angry = false;
	m_id = ++countObject;  //prefix increment
}


Cat::~Cat() //destructor function
{}

//* member functions can be defined outside the class body
void Cat::jump(){
	std::cout << "Jumping into muddy puddle!\n";
}


int Cat::getID(){
	return m_id;
}



