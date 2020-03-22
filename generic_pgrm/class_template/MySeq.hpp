/* *********************************************************
Author:      Roy Wu
Description: 
********************************************************* */
#ifndef MYSEQ
#define MYSEQ
#include<iostream>

//* ---class template example with default values and types---
template <class T = double, int N = 10>
class MySeq 
{
public:

	//* constructor
	MySeq() 
	{
		std::cout << "MySeq Constructor is called..\n";
	};

	//* destructor 
	~MySeq() {};
	
	void setMember(int x, T value);
	T    getMember(int x);
	int  testInt = 100; //* used in unit test

private:
	T memBlock[N];
};


//* --- setMember ---
template <class T, int N>
void MySeq<T, N>::setMember(int x, T value) 
{
	memBlock[x] = value;
}


//* --- getMember ---
template <class T, int N>
T MySeq<T, N>::getMember(int x) 
{
	return memBlock[x];
}
#endif //* MYSEQ
