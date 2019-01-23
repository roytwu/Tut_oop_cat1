/* file name: main.cpp
 * programmer: Roy T Wu
 * Project: tutorial for std::optional
 * Credit: https://www.bfilipek.com/2018/05/using-optional.html
 * Note: std::optional is not incorporated in VS2015, here boost::optional is applied
 */

#include <iostream>
#include <string>
#include <boost/optional.hpp>

using std::cout; 
using std::endl;
using std::string; 

class UserRecord {
public:
	UserRecord(const string& name, const boost::optional<string> nick, boost::optional<int> age)
		: mName( name )
		, mNick( nick )
		, mAge( age )
	{}

	friend std::ostream & operator << (std::ostream& stream, const UserRecord& user);

private:
	string mName;
	const boost::optional<string> mNick;
	boost::optional<int> mAge;
};

std::ostream& operator << (std::ostream& os, const UserRecord& user) {
	os << user.mName << " ";
	if (user.mNick) {
		os << *user.mNick << " ";
	}

	if (user.mAge) {
		os << "age of " << *user.mAge;
	}
	return os;
}





int main()
{
	UserRecord tim{ "Tim", string("SuperTim"), 16};
	UserRecord nano { "Nathan", boost::none, boost::none };

	cout << tim << endl;
	cout << nano << endl;
    return 0;

}

