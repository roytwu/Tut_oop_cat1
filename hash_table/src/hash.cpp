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
HashChain::HashChain(){

}

HashChain::HashChain(int m){

}