/* File name: main.cpp
 * Developer: Roy T Wu
 * Project:   tutorial for std::optional, 
              user name with an optional nickname and age
 * Credit:    https://www.bfilipek.com/2018/05/using-optional.html
 * Note:      std::optional is not incorporated in VS2015, here boost::optional is applied
 */

#include <iostream>
#include <string>
#include <boost/optional.hpp>

using std::cout; 
using std::endl;
using std::string; 

class UserRecord {
public:
	UserRecord(const string& name, const boost::optional<string> nickName, boost::optional<int> age)
		: mName( name )
		, mNickName( nickName )
		, mAge( age )
	{}

	friend std::ostream & operator << (std::ostream& stream, const UserRecord& user);

private:
	string mName;
	const boost::optional<string> mNickName;
	boost::optional<int> mAge;
};

std::ostream& operator << (std::ostream& os, const UserRecord& user) {
	os << user.mName << " ";
	if (user.mNickName) {
		os << *user.mNickName << " ";
	}

	if (user.mAge) {
		os << "age of " << *user.mAge;
	}
	return os;
}


int main()
{
	//* only one level of conversion works, so "SuperTim" must be wrapped by std::string
	UserRecord tim ( "Tim", string("SuperTim"), 16);
	UserRecord nano { "Nathan", boost::none, boost::none };
	cout << tim << endl;
	cout << nano << endl;
    return 0;
}

