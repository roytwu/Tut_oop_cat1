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
	string logFile = "imu_log.csv";
	string delimeter = ",";
	CSVReader o_reader(logFile, delimeter);
	vector<IMUData> v_dataList = o_reader.getData2();
	
	//for (IMUData foo : v_dataList) {
	//	foo.printData();
	//}

	//int i = 0;
	//while(i < v_dataList.size()) {
	//	IMUData o_imuData = v_dataList.at(i);
	//	o_imuData.printData();
	//	i++;
	//	cout << i << endl;
	////	i= i%v_dataList.size();
	//}

	//IMUData o_imuData = v_dataList.at(0);
	//o_imuData.accel_process();

	//cv::Mat test(100, 100, CV_8U, cv::Scalar::all(150));
	//cv::imshow("test_window", test);
	//cv::waitKey(0); //wait infinitely until any keystroke in the window

    return 0;
}

