/* *********************************************************
File name:   main.cpp 
Programmer:  Roy Wu
Description: Creating horizontal line pattern
********************************************************* */
#include <iostream>
#include <vector>
#include <string>
#include <Eigen/Core>             //* this needs to added before <opencv2/core/eigen.hpp>
#include <Eigen/Dense>            //* Eigen library: Matrix
#include <Eigen/Geometry>         //* Eigen library: quaternion
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp> 
#include <sstream>
using std::cout; 
using std::endl;
using std::string; 

int h = 200;
int w = 300;
int step = 5;

std::stringstream ss;
std::string name = "img_";
std::string type = ".png";

int main()
{
    int linewidth = 2;
    cv::Vec3b clrWHT = cv::Vec3b(255, 255, 255); //* white
    cv::Mat3b black = cv::Mat3b::zeros(h, w);

    cv::Mat3b img = black.clone();
    for (int idx = 0; idx < step; ++idx) 
    {
        for (int y = 0; y < h; ++y) 
        {
            const int pattern_pos = (y + idx) % step;
            if (pattern_pos < 2) 
            {
                img(cv::Rect(0, y, h, 1)).setTo(clrWHT);

                ss << name << y << type;
                std::string fileName = "../result/" + ss.str();
                ss.str("");
                cv::imwrite(fileName, img);
                cout << "fileName is ... " << fileName << endl;
            }
        }
    }
    return 0;
}
