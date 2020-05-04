
#include <algorithm>  //* fior lexicographical_compare()
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

//* password
std::string pw = "$this*Is#The&PassWord!"; 

//* --- compare 2 strings leicographically ---
std::string pwVerfication (std::string input)
{
	std::string output;
	if (input == pw)
	{
		//std::cout << "correct password\n";
		output = "00";
	}
	else if (input < pw) 
	{
		//std::cout << "input is leicographically less than the PW\n";
		output = "0100";
	}
	else if (input > pw)
	{
		//std::cout << "input is leicographically greater than the PW\n";
		output = "01ff";
	}
	return output;
}



int main()
{
	std::string output; //* intial guess, empty!
	std::string vf;     //* verification string
	
	//* base shall have all the allowable characteristics 
	//* list them according to Unicode characteristics 
	std::vector <std::string> base{"!", "#", "$", "%", "&", "(", ")", "*", "+", "-",
								   "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", 
								   "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P",
								   "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
	                               "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p",
								   "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

	std::vector<std::string>::iterator itr;

	bool flag = 0;  
	while (flag != 1 )
	{
		for (itr = base.begin(); itr!=base.end(); ++itr)
		{
			std::string increment = output + (*itr);
	
			vf = pwVerfication(increment);

			if (vf == "00")
			{
				//* entire password found
				flag = 1;  
				output = increment;
				break;
			}
			else if (vf == "01ff")
			{
				//* find one character, break, to look for the next one
				std::cout << "itr is..." << *(itr-1) << std::endl;
				output = output + *(itr-1);
				break;
			}
		}
	}
	std::cout << "Output is ... " << output << std::endl;
	
	
	//* --- approach 2, not finished
	//* for each character, apply pwVerfication() at the middle point of base
	//* and only look at the half side of the vector, this shall reduce the times of probeing

	/*
	int sizeV = base.size();
	int pos;
	std::vector<std::string>::iterator itr2;
	itr2 =base.begin();

	pos = sizeV/2; 
	
	bool flag2 = 0;
	while (flag2 == 0){
		vf = pwVerfication(*(itr2+pos));
		if (vf == "00")
		{
			std::cout << "itr2 is ..." << *(itr2+pos);
			flag2 = 1;  
		}
		else if (vf == "0100")
		{
			sizeV = sizeV/2;;
			pos = pos +sizeV/2;
			std::cout << "too small..." << pos << std::endl;
		}
		else if (vf == "01ff")
		{
			sizeV = sizeV/2;
			pos = pos -sizeV/2;
			std::cout << "too large";
		}
	}	
	*/


    std::cout << "\nEnd of the porgram...\n";
	return 0;
}
