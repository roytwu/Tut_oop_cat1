//* File name: tiger.cpp
//* Programmer: Roy T Wu

#include <iostream>
#include "cat.h"
#include "tiger.h"
using std::cout;
using std::endl;

//no-argument constructor for Tiger
//call a super-class constructor with an argument
Tiger::Tiger(): Cat(77){
	cout << "  --Tiger no-argument consructor called--" << endl;
}


void Tiger::attackAntelope(){ 
	cout << "  Tiger is attacking an entelope" << endl; 
} 