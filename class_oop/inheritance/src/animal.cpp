//File name: animal.cpp
//Programmer: Roy TWu


#include <iostream>
#include "animal.h"
#include "cat.h"
using std::cout;
using std::endl;

//constructor
Animal::Animal(){
	int m_id =0;
	cout << "--Animal no-argument consructor called.--" << endl;
}
	
void Animal::speak(){ 
	cout << "Grrrrr...." << endl; 
}
