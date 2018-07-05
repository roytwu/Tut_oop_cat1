#include <iostream>
#include "hash.h"
using std::cout;
using std::endl;

int main(){

	HashChain o_hash(5);

	Dict o_dict1("Han", "Solo");
	Dict o_dict2("Anakin", "Skywalker");
	Dict o_dict3("Obi-Wan", "Kenobi");
	Dict o_dict4("Luke", "Skywalker");

	o_hash.insertData(o_dict1);
	o_hash.insertData(o_dict2);
	o_hash.insertData(o_dict3);
	o_hash.insertData(o_dict4);
	o_hash.insertData(Dict("Darth", "Vader"));

	o_hash.displayTb();
	//cout << "Obi-Wan's last name is.. " << o_hash.search("Obi-Wan") << endl;

	o_hash.deleteData("Luke"); //simething is wrong here
	o_hash.displayTb();

	return 0;
}