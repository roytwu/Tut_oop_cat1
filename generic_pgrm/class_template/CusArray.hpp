/* *********************************************************
Author:      Roy Wu
Description: create custom array with different data types
********************************************************* */
#ifndef CUSARRAY
#define CUSARRAY

//* ---class template---
template <class CT>
class CusArray 
{
public:
	CusArray(CT arr[], int s);  //* constructor
	void print();

private:
	CT  *ptr;
	int size;
};

//* constructor
template <class CT>
CusArray<CT>::CusArray(CT arr[], int s) 
{
	ptr = new CT[s];
	size = s;
	for (int i = 0; i < size; i++) 
	{
		ptr[i] = arr[i];
	}
}

//* member function 
template <class CT>
void CusArray<CT>::print() 
{
	for (int i = 0; i < size; i++) 
	{
		cout << " " << *(ptr + i);
	}
	cout << endl;
}



#endif //* CUSARRAY