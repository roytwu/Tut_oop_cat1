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
	Animal();                //*no-argument constructor
	Animal(int m_animalID);  //*parameterized contstructor
	virtual ~Animal();       //*make destructor virtual for polymorphism

	virtual void speak() = 0;  //* pure virtual function --> abstract class!
	void info();
};


void Animal::info() {
	cout << "  animalID is ... " << m_animalID << endl;
}

#endif //*ANIMAK_H_