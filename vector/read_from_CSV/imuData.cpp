//* file name:  imuData.cpp
#include <cmath>
#include <string>
//#include <opencv2/core/matx.hpp>
#include "imuData.h"
using std::pow;  //* cmath

//* overloaded constructor
IMUData::IMUData(vector<string> v_str) {
	m_rawAccel.push_back(std::stod(v_str[1]));
	m_rawAccel.push_back(std::stod(v_str[2]));
	m_rawAccel.push_back(std::stod(v_str[3]));

	m_rawGyro.push_back(std::stod(v_str[4]));
	m_rawGyro.push_back(std::stod(v_str[5]));
	m_rawGyro.push_back(std::stod(v_str[6]));

	m_rawMag.push_back(std::stod(v_str[7]));
	m_rawMag.push_back(std::stod(v_str[8]));
	m_rawMag.push_back(std::stod(v_str[9]));

	m_rawTem = std::stod(v_str[10]);
}


void IMUData::printData() {
	vector<double>::iterator itr;
	for (itr = m_rawAccel.begin(); itr != m_rawAccel.end(); itr++) {
		cout << *itr << " ";
	}
	cout << ", ";
	for (itr = m_rawGyro.begin(); itr != m_rawGyro.end(); itr++) {
		cout << *itr << " ";
	}
	cout << ", ";
	for (itr = m_rawMag.begin(); itr != m_rawMag.end(); itr++) {
		cout << *itr << " ";
	}
	cout << ", ";
	cout << m_rawTem << ". " << endl;
}

vector<double> IMUData::accel_process() {
	double x_acc = (m_rawAccel.at(0) - x_acc_offset)* acc_scale;
	double y_acc = (m_rawAccel.at(1) - y_acc_offset)* acc_scale;
	double z_acc = (m_rawAccel.at(2) - z_acc_offset)* acc_scale;
	m_acc.push_back(x_acc);
	m_acc.push_back(y_acc);
	m_acc.push_back(z_acc);

	double  alpha = atan2(-y_acc, x_acc);
	double  beta = atan2(-x_acc, sqrt(pow(y_acc, 2) + pow(z_acc,2)));

	return m_acc;
}
