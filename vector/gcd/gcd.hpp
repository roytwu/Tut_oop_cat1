/* *********************************************************
Author:      Roy Wu
Description: GCD function
********************************************************* */
#ifndef GCD_H
#define GCD_H
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream_iterator; //* writes an output stream


int findGCD(int num, int* arr)
{
	cout << "\nFunction starts here...\n";
	//* find the minimum element in the array
	int min = arr[0];
	for (int i = 1; i < num; i++)
	{
		if (min - arr[i] > 0)
			min = arr[i];
	}
	//cout << "Minimal element is..." << min << endl;

	//* find all the divisors of min and put them into a vector
	vector<int> divi;
	for (int i = 1; i <= min; i++)
	{
		if (min % i == 0)
		{
			divi.push_back(i);
			//cout << "i is..." << i << endl;
		}
	}

	//* use a reverse iterator to access elements from the end
	vector<int>::reverse_iterator ritr;
	bool isItADivisor;
	int gcd = 1;
	for (ritr = divi.rbegin(); ritr != divi.rend(); ++ritr)
	{
		isItADivisor = true;
		for (int i = 0; i < num; i++)
		{
			if (arr[i] % (*ritr) != 0)
			{
				cout << "ritr is ... " << *ritr << endl;
				isItADivisor = false;
			}
		}

		if (isItADivisor == true)
		{
			gcd = *ritr;
			break;
		}

	}
	return gcd;
}

#endif //* GCD_H