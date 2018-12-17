/* file name: main.cpp
 * programmer: Roy T Wu
 * Project: reading data from a CSV file*/

//#include <iostream>
#include <vector>
#include "readCSV.hpp"

//using std::cout; 
//using std::endl;
using std::vector;

int main()
{
	// Approach 1 -- basic version 
	string logFileName = "imu_log.csv";
	ifstream o_IMULogFile;
	o_IMULogFile.open(logFileName);


	if (o_IMULogFile.is_open()) {
		string line;
		while (o_IMULogFile) {
			//getline(o_IMULogFile, line, ',');
			getline(o_IMULogFile, line);

			cout << line << endl;
		}
		o_IMULogFile.close();
	}
	else {
		cout << "Could not open file " << logFileName << endl;
	}


	// Apporach 2- use readCSV.hpp
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

