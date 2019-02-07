#include <iosfwd>
#include <iostream>
#include <string>
#include "message.hpp"
using std::ostream;
using std::endl;

ostream &Message::printObject(ostream &os) {
	os << "This is my very nice message..." << endl;
	os << message_;

	return os;
}