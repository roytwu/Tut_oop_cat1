//File name: main.cpp
//Author: Roy T Wu
//Goal: inverse a string

#include <iostream>
#include <string>
#include "strInverse.h"
using std::string;
using std::cout;
using std::endl;


int main(){
  	string str1 = "This is a string!";
  	string str2 = "Rats live on NO evil star";	
	string str3 = "No lemon, no melon~~";

  	cout << "Before inverse.. " << str1 << endl;
  	cout << "After inverse... " << flipString_XOR(str1) << endl;
  	cout << endl;

  	string newStr = flipString_XOR(str2);
  	cout << "Before inverse.. " << str2 << endl;
  	cout << "After inverse... " << newStr << endl;

  	flipString_swap(str2); 
  	cout << endl << str2 << endl;

	cout << "\n-------- 2020 Jan -------\n";
	string result = stringInvXOR(str2);
	cout << result << endl;

	return 0 ;
}