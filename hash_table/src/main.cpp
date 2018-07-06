#include <iostream>
#include <unordered_map>
#include <utility>  //make_pair()
#include "hash.h"
using std::cout;
using std::endl;
using std::unordered_map;
using std::make_pair;

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
	cout << "Obi-Wan's last name is.. " << o_hash.search("Obi-Wan") << endl << endl;

	o_hash.deleteData("Luke"); 
	o_hash.displayTb();

	//unordered_map is already a hash table 
	unordered_map<string, string> umap;
	umap["Han"] = "Solo";
	umap["Anakin"] = "Skywalker";
	umap["Obi-Wan"] = "Kenobi";
	umap["Luke"] = "Skywalker";
	umap.insert(make_pair("Darth", "Vader"));

	unordered_map<string, string>::iterator itr;
	cout << "----- ----- unordered_map ----- -----" << endl;
    cout << "All Elements in umap : \n";

  
    	
    for (itr = umap.begin(); itr != umap.end(); itr++){
        	cout << "(" <<itr->first << "  " << itr->second << ")" << endl;
    }
	

	return 0;
}