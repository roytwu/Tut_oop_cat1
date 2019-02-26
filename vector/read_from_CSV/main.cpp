/* file name: main.cpp
 * programmer: Roy T Wu
 * Project: reading data from a CSV file*/

#include <fstream>
#include <iostream>
#include <vector>
#include <opencv2/core/matx.hpp>
#include <opencv2/opencv.hpp>
//#include "estimation.h"
#include "imuData.h"
#include "readCSV.h"

//using std::cout; 
//using std::endl;
using std::vector;

int main(int argc, char** argv)
{
	////* Approach 1 -- basic version 
	//string logFileName = "imu_log.csv";
	//string line;
	//ifstream o_logFile;
	//o_logFile.open(logFileName);

	//if (o_logFile.is_open()) {
	//	while (getline(o_logFile, line)) {
	//		//getline(o_logFile, line, ',');
	//		getline(o_logFile, line);

	//		cout << line << endl;
	//	}
	//	o_logFile.close();
	//}
	//else {
	//	cout << "Could not open file... " << logFileName << endl;
	//}


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
	//string logFile = "imu_log.csv";
	string logFile = "imu_stable_LSB.csv";
	string delimeter = ",";
	CSVReader o_reader(logFile, delimeter);
	vector<IMUData> v_dataList = o_reader.getData2();
	

	int odr = 500; //* output data rate

	double t = 0.0;
	double dt = 1.0f; 

	


	//* attitude part
	for (IMUData o_foo : v_dataList) {
		//o_foo.printData(); //* print data
		o_foo.accel_process();
		o_foo.mag_process();

		cv::Matx33d R0= o_foo.initial_att();
		cout << R0 << endl;
	}


    return 0;
}

