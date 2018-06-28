//file name: inverseStr.h
//author: Roy T Wu

#ifndef INVERSESTR_H_
#define INVERSESTR_H_

#include <string>
using std::string;
using std::swap;


class StringInverse{
public:
	string flipString_xor(string str);
	void flipString_swap(string& str);
private:
	void flipChar_xor(char *p_a, char *p_b);

};


string StringInverse::flipString_xor(string str){
	char * p_first = &str[0]; //address of the first char in string
	char * p_last =  &str[str.length()-1]; // address of the last char in string
	while(p_first < p_last)
	{
		flipChar_xor(p_first, p_last);

		//moving toward to next pair of char
		p_first++;  
		p_last--;
	} //while
	return str;
}

void StringInverse::flipString_swap(string& str){
	int len= str.length();
	for(int i=0; i<len/2; i++){
		swap(str[i], str[len-i-1]);
	}
}

//inverse a pair of char using bitwise xor
void StringInverse::flipChar_xor(char *p_a, char *p_b)
{
	*p_a ^= *p_b; //1st step, bitwise XOR, *p_a=*p_a^*p_b
	*p_b ^= *p_a; //2nd step
	*p_a ^= *p_b; //3rd step
}

/*
1st step: 
          pa = 01001
          pb = 10011
  updated pa = 11010

2nd step: 
          pb = 10011
          pa = 11010
  updated pb = 01001 (which is equivalent to original pa)

3rd step:
          pa = 11010
          pb = 01001
  updated pa = 10011 (which is equivalent to original pb)                               	 
*/  
 


#endif //INVERSE_H_