//* file name:  imuData.h
#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

class IMUData {
public:
	vector<double> m_rawAccel; //* accelerometer 
	vector<double> m_rawGyro;  //* gyroscope
	vector<double> m_rawMag;   //* magnetometer 
	double m_rawTem;           //* temperature sensor

	vector<double> m_acc;      //* accelerometer 
	vector<double> m_gyro;     //* gyroscope
	vector<double> m_mag;      //* magnetometer 

	IMUData(vector<string>);  //* overloaded constructor

	void printData();

	vector<double> accel_process();

private:
	double x_acc_offset = 0;
	double y_acc_offset = 0;
	double z_acc_offset = 0;
	double acc_scale  = 1/16384;
	double gyro_scale = 1/131;
	double mag_scale  = 0.15;

};