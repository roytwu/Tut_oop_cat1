#pragma once

#include <iosfwd>
#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::endl;

class Message{
public:
	Message(strubg &m) : message_(m) {}

	firend ostream & operator << (ostream &os, Message &obj) {
		return obj.printObject(os);
	}
private:
	string message_; 
	ostream &printObject(ostream &os);
};

ostream &Message::printObject(ostream &os) {
	os << "This is my very nice message" << endl;
	os << message_;

	return os;
}