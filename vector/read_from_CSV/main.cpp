/* file name: main.cpp
 * programmer: Roy T Wu
 * Project: reading data from a CSV file*/

#include <iostream>
#include <vector>
#include "imuData.h"
#include "readCSV.h"

//using std::cout; 
//using std::endl;
using std::vector;

int main()
{
	//* Approach 1 -- basic version 
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


	//* Apporach 2 -- use readCSV.hpp 
	//CSVReader o_reader("imu_log.csv");
	//vector< vector<std::string> > v_dataList = o_reader.getData();
	//cout << "# of rows in CSV file: " << v_dataList.size() << endl;

	//for (vector<std::string> vec : v_dataList) {
	//	//cout << "# of columns in CSV file: " << vec.size() << endl;
	//	for (std::string data : vec) {
	//		cout << data << ", ";
	//	}
	//	cout << endl;
	//}

	//* Apporach 3 -- use readCSV.hpp with getData2()
	string delimeter = ",";
	CSVReader o_reader(logFileName, delimeter);
	vector<IMUData> v_dataList = o_reader.getData2();
	
	for (IMUData foo : v_dataList) {
		foo.printData();
	}

    return 0;
}

