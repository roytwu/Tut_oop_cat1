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
	cout << "Status of Tommy kitty:" << endl;
	tom.happy = true; 
	tom.speak();
	tom.jump();
	cout << endl;

	cout << "Status of Nancy kitty:" << endl;
	nancy.happy = false;
	nancy.speak();
	cout << endl;

	//Test private key "angry", which is a better coding practice
	cout << "Status of Bobby kitty:" << endl;
	bob.makeAngry();
	bob.speak();

    // cout << endl << endl;
    // {
    // 	cout << "Status of Jacky kitty:" << endl;
    // 	Cat jacky ; 
    // 	jacky.speak();
    // }

    cout << "Ending porgram..." <<endl;
	return 0;
}