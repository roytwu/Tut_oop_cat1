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
	double x_acc = (m_rawAccel.at(0) - x_acc_offset)* acc_scale; //*gee
	double y_acc = (m_rawAccel.at(1) - y_acc_offset)* acc_scale;
	double z_acc = (m_rawAccel.at(2) - z_acc_offset)* acc_scale;
	m_acc.push_back(x_acc);
	m_acc.push_back(y_acc);
	m_acc.push_back(z_acc);

	double one_gee = sqrt(pow(x_acc,2) +pow(y_acc, 2) +pow(z_acc, 2));

	double theta = atan2(y_acc, z_acc); //*radian
	double phi = atan2(x_acc, sqrt(pow(y_acc, 2) + pow(z_acc,2))); //* radian
	return m_acc;
}

vector<double> IMUData::gyro_process() {
	double x_gyro = (m_rawGyro.at(0) - x_gyro_offset)* gyro_scale; //* degree per second
	double y_gyro = (m_rawGyro.at(1) - y_gyro_offset)* gyro_scale;
	double z_gyro = (m_rawGyro.at(2) - z_gyro_offset)* gyro_scale;
	m_gyro.push_back(x_gyro);
	m_gyro.push_back(y_gyro);
	m_gyro.push_back(z_gyro);

	return m_gyro;
}

vector<double> IMUData::mag_process() {
	double x_mag = (m_rawMag.at(0) - x_mag_offset)* mag_scale; 
	double y_mag = (m_rawMag.at(1) - y_mag_offset)* mag_scale;
	double z_mag = (m_rawMag.at(2) - z_mag_offset)* mag_scale;
	m_mag.push_back(x_mag);
	m_mag.push_back(y_mag);
	m_mag.push_back(z_mag);

	return m_mag;
}

cv::Matx33d IMUData::initial_att() {
	//double theta = atan2(y_acc, z_acc); //*radian
	//double phi = atan2(x_acc, sqrt(pow(y_acc, 2) + pow(z_acc, 2))); //* radian
	double theta = atan2(m_acc.at(1), m_acc.at(2));
	double phi = atan2(m_acc.at(0), sqrt(pow(m_acc.at(1), 2) + pow(m_acc.at(2), 2)));

	double Hx = m_mag.at(0)*cos(theta) - m_mag.at(1)*sin(phi)*sin(theta) - m_mag.at(2)*sin(phi)*sin(theta);
	double Hy = -m_mag.at(1)*cos(theta) + m_mag.at(2)*sin(theta);
	double psi = atan2(Hx, Hy);

	cv::Matx33d Rx(1, 0, 0, 0, cos(theta), -sin(theta), 0, sin(theta), cos(theta));
	cv::Matx33d Ry(cos(phi), 0, sin(phi), 0, 1, 0, -sin(phi), 0, cos(phi));
	cv::Matx33d Rz(cos(psi), -sin(psi), 0, sin(psi), cos(psi), 0, 0, 0, 1);
	cv::Matx33d Rzyx = Rz*Ry*Rx;
	
	return Rzyx;
}