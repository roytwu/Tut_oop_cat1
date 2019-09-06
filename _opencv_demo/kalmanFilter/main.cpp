/* *********************************************************
File name:   main.cpp (_kalman)
Programmer:  Roy Wu
Description: sandbox of Kalman filteting implementation
********************************************************* */
#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
using std::cout; 
using std::endl;

//void findMatrixSize(cv::Mat_<double> & m) 
void findMatrixSize(cv::Mat & m)
{
	//* approach #1 - using cv::Size
	cv::Size s = m.size();
	int r1 = s.height;
	int c1 = s.width;
	//* approach #2 - without cv::Size
	int r2 = m.rows;
	int c2 = m.cols;
	cout << "(" << r1 << ", " << c1 << ")" << endl;
	cout << "(" << r2 << ", " << c2 << ")" << endl;
}


int main()
{
	unsigned int type = CV_64F; //* CV_64 for double, CV_32 for float
	//cout << "\n----- H -----\n";
	cv::Matx66d p0 = cv::Matx66d::eye(); //* state err covariance matx
	cv::Mat h;
	cv::hconcat(cv::Matx33d::all(0), cv::Matx33d::eye(), h);
	cout << "Observation matrix H (3x6):  \n" << h << endl << endl;

	//cout << "\n----- F -----\n";
	double dt = 0.001;
	cv::Mat dummyF1, dummyF2;
	cv::Matx66d f66;
	cv::Matx33d f33 = dt*cv::Matx33d::eye();
	cv::hconcat(cv::Matx33d::eye(), f33, dummyF1);
	cv::hconcat(cv::Matx33d::all(0), cv::Matx33d::eye(), dummyF2);
	cv::vconcat(dummyF1, dummyF2, f66);
	cout << "system state matrix F (6x6):  \n" << f66 << endl << endl;

	//* find matrix size, need to convert from Matx to Mat_ or Mat first
	//findMatrixSize(cv::Mat_<double>(f66));
	findMatrixSize(cv::Mat(f66));

	cout << "\n----- concatenating multiple matrices -----\n";
	double e0[3][4] = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
	double e1[3][3] = { {1,1,1},   {1,1,1},   {1,1,1} };
	double e2[3][2] = { {2,2},     {2,2},     {2,2} };
	double e3[3][1] = { {3},       {3},       {3}  };
	cv::Mat mat_e0 = cv::Mat(3, 4, type, e0);
	cv::Mat mat_e1 = cv::Mat(3, 3, type, e1);
	cv::Mat mat_e2 = cv::Mat(3, 2, type, e2);
	cv::Mat mat_e3 = cv::Mat(3, 1, type, e3);
	std::vector<cv::Mat> matrices{mat_e0, mat_e1, mat_e2, mat_e3};
	cv::Mat e0123;
	cv::hconcat(matrices, e0123);
	cout << e0123 << endl;

	cout << "\n----- Initialize cv::Mat in different ways -----\n";
	double arr_foo[3][6] = { { 1.0, 0., 0., 0., 0., 0. },
	                       	 { 0., -1., 0., 0., 0., 0. },
		                     { 0., 0., -1., 0., 0., 0. } };
	cv::Matx<double, 3, 6> foo3x6 = cv::Mat(3, 6, type, arr_foo);
	cout << foo3x6 << endl;

	//* initialize cv::Mat with cv::Size
	//* note that cv::Size is defined by (width, height)
	cv::Mat m_0_3x1 = cv::Mat::zeros(cv::Size(3, 1), type); //* all zeros, row vector
	cv::Mat m_2_3x1(cv::Size(1, 3), type, cv::Scalar(2));   //* all 2, column vector
	
	//* Vec3d by default output row vector
	cv::Vec3d vec_a = cv::Vec3d(0, 7, 0);  
	cv::Vec3d vec_b = cv::Vec3d(1, 1, 1);
	cv::Vec3d vec_c = vec_a + vec_b;
	cout << "vec_c is ... " << vec_c << endl;

	cv::Vec3d vec_d;
	cout << "\n--- Scenario 1 ---\n";
	cv::Mat mat_a = cv::Mat(1, 3, type, cv::Scalar(0)); //* initialize mat_a as row vector
	vec_d = vec_a + cv::Vec3d(mat_a);     
	cout << "mat_a is ... " << mat_a << endl;
	cout << "vec_d is ... " << vec_d << endl;
	
	cout << "\n--- Scenario 2 ---\n";
	mat_a = m_2_3x1 + cv::Mat(vec_b);  //* mat_a is automatically converted to column vector
	vec_d = cv::Vec3d(mat_a);  //* vec_d is  still a row vector
	cout << "mat_a is ... \n" << mat_a << endl;
	cout << "vec_d is ... " << vec_d << endl;


	double arr_quatIdentity[4] = { 1., 0., 0., 0. };
	cv::Mat dQ_CB = cv::Mat(1, 4, type, cv::Scalar(0.));
	cout << "\ndQ_CB is ... \n" << dQ_CB << endl;

	double arr_bar[4][4] = {{11, 12, 13, 14}, {21, 22, 23, 24},
							{31, 32, 33, 34}, {41, 42, 43, 44} };
	cv::Matx44d bar4x4 = cv::Mat(4, 4, type, arr_bar);
	cv::Matx44d & pt_bar4x4 = bar4x4;
	cv::Matx41d augPos = pt_bar4x4.col(3);       
	cout << augPos << endl;

    return 0;
}

