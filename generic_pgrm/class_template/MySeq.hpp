/* *********************************************************
Author:      Roy Wu
Description: custom array and fill in arry element by element
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
	~MySeq() 
	{
		std::cout << "MySeq Destructor is called..\n";
	};
	
	void setMember(int position, T value);
	T    getMember(int position);
	int  testInt = 100; //* used in unit test

private:
	T memBlock[N];
};


//* --- setMember ---
template <class T, int N>
void MySeq<T, N>::setMember(int position, T value) 
{
	memBlock[position] = value;
}


//* --- getMember ---
template <class T, int N>
T MySeq<T, N>::getMember(int position) 
{
	int size = sizeof(memBlock) / sizeof(*memBlock);
	try 
	{
		return memBlock[position];
	}
	catch (...)
	{
		std::cout << "something is wrong\n";
	}
}
#endif //* MYSEQ
