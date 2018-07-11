//file name: tiger.h
//Programmer: Roy T Wu

#ifndef TIGER_H_
#define TIGER_H_

#include "cat.h"

#include <iostream>
using std::cout;
using std::endl;

class Tiger: public Cat{
public:
	Tiger(){
		cout << " --Tiger no-argument consructor called--" << endl;
	}
	
	void attackAntelope(){ 
		cout << " Tiger is attacking an entelope" << endl; 
	} 
};

#endif //TIGER_H_