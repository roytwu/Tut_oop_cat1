/* *********************************************************
Author:      Roy T Wu
Description: sub-class
********************************************************* */
#include <iostream>
#include "animal.h"
#include "cat.h"
using std::cout;
using std::endl;

//* static variables can't be initialized in the class, so, 
//* it's common practice to initialize static variable in cpp file
int Cat::countObject = 0;

Cat::Cat() //* no-argument consructor
{
	cout << "\t--Cat no-argument consructor called.--" << endl;
	m_angry = false;
	m_id = ++countObject;  //* prefix increment
}

//* call a super-class constructor with an argument
Cat::Cat(int m_animalID): Animal(m_animalID) //pameterized consructor inheritance
{	
	cout << "\t--Cat parameterized consructor called.--" << endl;
	m_angry = false;
	m_id = ++countObject;  //* prefix increment
}


Cat::~Cat() //* destructor function
{
	//cout << "Cat desructor called. Cat destroyed." << endl;
}

//* member functions can be defined outside the class body
void Cat::makeAngry()
{
	m_angry = true;
}


void Cat::makeSad()
{
	m_angry = false;
}


void Cat::speak()
{
	if(m_happy){
		cout << "\tMeouww! kitty is happy!(cat speaking)" << endl;	
	} 
	else if(m_angry){
		cout << "\tkrrr!! Fuck off!(cat speaking)" << endl;
	}
	else{
		cout << "\tSsssss...(cat speaking)" << endl;
	}
}


void Cat::jump()
{
	cout << "\tCat jumps into a muddy puddle!" << endl;
}


int Cat::getID()
{
	return m_id;
}
