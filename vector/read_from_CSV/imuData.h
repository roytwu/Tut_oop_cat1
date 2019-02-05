#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class IMUData {
public:
	vector<double> m_accel; //* accelerometer 
	vector<double> m_gyro;  //* gyroscope
	vector<double> m_mag;   //* magnetometer 
	double m_tem;            //* temperature sensor

	IMUData(vector<string>);  //overloaded constructor

	void printData();

	//friend class CSVReader;
};