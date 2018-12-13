//#include <iostream>
#include <vector>
#include "readCSV.hpp"

//using std::cout; 
//using std::endl;
using std::vector;

int main()
{
	CSVReader o_reader("imu_log.csv");

	vector< vector<std::string> > v_dataList = o_reader.getData();

	for (vector<std::string> vec : v_dataList) {
		for (std::string data : vec) {
			cout << data << ", ";
		}
		cout << endl;
	}

    return 0;
}

