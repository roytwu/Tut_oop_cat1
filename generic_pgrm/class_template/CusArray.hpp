/* *********************************************************
Author:      Roy Wu
Description:
********************************************************* */
#ifndef CusArray
#define CusArray

//* ---class template---
template <class CT>
class Cus_Array 
{
public:
	Cus_Array(CT arr[], int s);  //* constructor
	void print();

private:
	CT  *ptr;
	int size;
};

//* constructor
template <class CT>
Cus_Array<CT>::Cus_Array(CT arr[], int s) 
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
void Cus_Array<CT>::print() 
{
	for (int i = 0; i < size; i++) 
	{
		cout << " " << *(ptr + i);
	}
	cout << endl;
}



#endif //* CusArray