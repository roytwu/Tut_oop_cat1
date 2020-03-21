/* *********************************************************
Author:      Roy Wu
Description: 
********************************************************* */
#ifndef MYSEQ
#define MYSEQ

//* ---class template example with default values and types---
template <class T = double, int N = 10>
class MySeq {
public:
	void setMember(int x, T value);
	T getMember(int x);

private:
	T memBlock[N];
};

template <class T, int N>
void MySeq<T, N>::setMember(int x, T value) {
	memBlock[x] = value;
}

template <class T, int N>
T MySeq<T, N>::getMember(int x) {
	return memBlock[x];
}




#endif //* MYSEQ
