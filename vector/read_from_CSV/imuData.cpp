#include "imuData.h"

//overloaded constructor
IMUData::IMUData(vector<string> v_str) {
	m_accel.push_back(std::stod(v_str[1]));
	m_accel.push_back(std::stod(v_str[2]));
	m_accel.push_back(std::stod(v_str[3]));

	m_gyro.push_back(std::stod(v_str[4]));
	m_gyro.push_back(std::stod(v_str[5]));
	m_gyro.push_back(std::stod(v_str[6]));

	m_mag.push_back(std::stod(v_str[7]));
	m_mag.push_back(std::stod(v_str[8]));
	m_mag.push_back(std::stod(v_str[9]));

	m_tem = std::stod(v_str[10]);
}


void IMUData::printData() {
	vector<double>::iterator itr;
	for (itr = m_accel.begin(); itr != m_accel.end(); itr++) {
		cout << *itr << " ";
	}
	cout << ", ";
	for (itr = m_gyro.begin(); itr != m_gyro.end(); itr++) {
		cout << *itr << " ";
	}
	cout << ", ";
	for (itr = m_mag.begin(); itr != m_mag.end(); itr++) {
		cout << *itr << " ";
	}
	cout << ", ";
	cout << m_tem << ". " << endl;
}
