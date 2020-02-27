/* *********************************************************
File name:   animal.h
Author:      Roy T Wu
Description: 
********************************************************* */
#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <iostream>
using std::cout;
using std::endl;

//* Animal is a super-calss of Cat
class Animal{
private:
	int m_animalID;
	
public:
	//* no-argument constructor
	Animal() {};       

	//* parameterized contstructor
	Animal(int m_animalID) { this->m_animalID = m_animalID;};

	//*make destructor virtual for polymorphism
	virtual ~Animal()	{};

	//* pure virtual function --> abstract class!
	virtual void speak() = 0;  
	
	void info() { cout << "  animalID is ... " << m_animalID << endl; };
};

#endif //*ANIMAK_H_