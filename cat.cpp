//File name: cat.cpp
//Programmer: TWu

#include <iostream>
#include "cat.h"
using std::cout;
using std::endl;

void Cat::makeAngry(){
	angry = true;
}

void Cat::makeSad(){
	angry = false;
}

void Cat::speak(){
	if(happy){
		cout << "Meouww! kitty is happy!" << endl;	
	} 
	else if(angry){
		cout << "krrr!! Fuck off!" << endl;
	}
	else{
		cout << "Ssssss..." << endl;
	}
}

void Cat::jump(){
	cout << "Jumping into muddy puddle!" << endl;
}

