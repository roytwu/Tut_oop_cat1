/* *********************************************************
File name:   main.cpp (_openCVBasic)
Programmer:  Roy Wu
Description: Demo aoubt photo stacking
********************************************************* */
#include <iostream>
#include <vector>
#include <string>
#include <Eigen/Core>             //* this needs to added before <opencv2/core/eigen.hpp>
#include <Eigen/Dense>            //* Eigen library: Matrix
#include <Eigen/Geometry>         //* Eigen library: quaternion
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp> 
using std::cout; 
using std::endl;
using std::string; 

int main()
{
    cv::Mat img;
    string fileName = "D:/RoyTWu/repo/learn_cpp/_opencv_demo/photoStacking/image001.png";
    img = cv::imread(fileName, cv::IMREAD_COLOR);

    if (img.empty()) //* Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    //* Create a window for display.
    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE); 
    
    //* Show our image inside it.
    cv::imshow("Display window", img);

    cv::waitKey(0);
    return 0;
}
