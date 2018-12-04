#pragma once

#include <iosfwd>
#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::endl;

class Message{
public:
	Message(const string &m) : message_(m) {}

	friend ostream & operator << (ostream &os, Message &obj) {
		return obj.printObject(os);
	}
private:
	string message_; 
	ostream &printObject(ostream &os);
};

