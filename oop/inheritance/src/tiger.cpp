/* *********************************************************
File name:   tiger.cpp (_inheritance)
Programmer:  Roy T Wu
Description: sub-sub-class
********************************************************* */
#include <iostream>
#include "cat.h"
#include "tiger.h"


//* no-argument constructor for Tiger
//* call a super-class constructor with an argument
Tiger::Tiger(): Cat(77){
	cout << "  --Tiger no-argument consructor called--" << endl;
}


void Tiger::attackAntelope(){ 
	cout << "  Tiger is attacking an entelope" << endl; 
} 