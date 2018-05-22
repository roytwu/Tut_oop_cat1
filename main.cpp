/* 
main file for cat.cpp and cat.h
The structure of class "Cat" is defined in cat.h
and the functions of "Cat" are defined in cat.cpp

In this program, name different cats like "tom", "nancy"
*/
//File name: main.cpp
//Programmer: TWu

#include <iostream>
#include "cat.h"
using std::cout;
using std::endl;

int main(){
	Cat tom, nancy, bob; //define objects within class "Cat"
	
	//Test public key "happy"
	tom.happy = true; 
	tom.speak();
	tom.jump();
	cout << endl;

	nancy.happy = false;
	nancy.speak();
	cout << endl;

	//Test private key "angry", which is a better coding practice
	bob.makeAngry();
	bob.speak();

	return 0;
}