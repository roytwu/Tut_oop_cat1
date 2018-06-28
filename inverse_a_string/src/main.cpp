//File name: main.cpp
//Author: Roy T Wu
//Goal: inverse a string

#include <iostream>
#include <string>
#include "inverseStr.h"
using std::string;
using std::cout;
using std::endl;


int main(){
  	string str1 = "This is a string!";
  	string str2 = "Rats live on NO evil star";
	StringInverse o_flip;  	

  	cout << "Before inverse.. " << str1 << endl;
  	cout << "After inverse... " << o_flip.flipString_xor(str1) << endl;
  	cout << endl;

  	cout << "Before inverse.. " << str2 << endl;
  	cout << "After inverse... " << o_flip.flipString_xor(str2) << endl;
	return 0 ;
}