#include "hash.h"
/*----- -----class Dict----- -----*/
Dict::Dict(){
	m_key = "";
	m_value = "";
}

Dict::Dict(string k, string v){
	m_key = k;
	m_value = v;	

}


/*----- -----class HashChain----- -----*/
//private member functions

//preHashing: turn string key to int key
int HashChain::preHashing(string key_str){
	int exp = 3;
	int key_int = 0;
	int p = 1;

	for(int i=(int)key_str.length()-1; i>=0; i--){
		key_int += key_str[i]*p;
		p *= exp;
	}
	return key_int;
}

int HashChain::hashFunc(string key_str){

	int division = preHashing(key_str) % (this->m_size);
	return division;
}


//public member functions

//constructor
HashChain::HashChain(){

}


//constructor overload
HashChain::HashChain(int m){

}


void HashChain::insert_data(Dict data){
	//get index from the hash function
	int index = hashFunc(data.m_key); 

	//insert data at the front of linked list
	mv_table[index].push_front(data); 
}


void HashChain::delete_data(string key_str){
	//get index from the hash function
	int index = hashFunc(key_str);
	list<Dict>::iterator i;   //delcare a list iterator
	for(i=mv_table[index].begin(); i!=mv_table[index].end(); i++){
		if( (*itr).m_key == key_str )
			mv_table[index].erase(itr);

	} 

}

string HashChain::search(string key_str){
	//get index from the hash function
	int index = hashFunc(key_str);
	list<Dict>::iterator i;   //delcare a list iterator
	for(i=mv_table[index].begin(); i!=mv_table[index].end(); i++){
		if( (*itr).m_key == key_str )
			return (*itr).m_value;

	} 

	return "...\n NO SUCH DATA";
}


void HashChain::displayTb(){

	for(int i=0; i<mv_table.length(); i++){
		cout << "slot#" << i << ": ";
		
		list<Dict>::iterator i;   //delcare a list iterator
		for(i=mv_table[index].begin(); i!=mv_table[index].end(); i++){
			cout << (*itr).m_key << ", " << (*itr).m_value;
		} 
		cout << endl;
	}
	cout << endl;
}


/*-----Note-----*/
//See vector_basic.cpp in vector project to know more about vector iterators