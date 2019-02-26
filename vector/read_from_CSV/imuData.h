//* file name:  imuData.h
#pragma once
#ifndef IMUDATA_H_
#define IMUDATA_H_


#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>


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

	vector<double> m_pos;      //* position
	vector<double> m_vel;      //* velocity

	IMUData(vector<string>);  //* overloaded constructor

	void printData();

	vector<double> accel_process();
	vector<double> gyro_process();
	vector<double> mag_process();
	cv::Matx33d initial_att();

	vector<double> integ_pos(double);


private:
	double x_acc_offset = 0;
	double y_acc_offset = 0;
	double z_acc_offset = 0;
	double x_gyro_offset = 0;
	double y_gyro_offset = 0;
	double z_gyro_offset = 0;
	double x_mag_offset = 0;
	double y_mag_offset = 0;
	double z_mag_offset = 0;
	double acc_scale  = 1/16384;
	double gyro_scale = 1/131;
	double mag_scale  = 0.15;

};

#endif //*IMUDATA_H_