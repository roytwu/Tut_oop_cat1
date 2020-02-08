/* *********************************************************
File name:   main.cpp (_openCVBasic)
Programmer:  Roy Wu
Description: Demo of photo stacking
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
    std::vector<cv::Mat> imgTote;
    cv::Mat avgImg;
    int height;
    int width; 

    //cv::String folder = "../Indoor_Guitars";
    cv::String folder = "../stackingSample/aligned/png";
    std::vector<cv::String> fileNames;
    cv::glob(folder, fileNames);

    int num = fileNames.size(); //* number of images
    imgTote.reserve(num);
    
    cout << "Start reading files...\n";
    for (size_t i = 0; i < num; i++) 
    {
        cv::Mat img = cv::imread(fileNames[i]);

        if (img.empty()) //* Check for invalid input
        {
            cout << "Could not open or find the image\n";
            return -1;
        }
        imgTote.push_back(img);
        //cout << "Image size is ..." << img.size() << endl;
 
    }

    height = imgTote[0].rows;
    width = imgTote[0].cols;
    //cout << "width is ..."  << width << endl;
    //cout << "height is ..." << height << endl;

    cout << "\nFinished reading files...\n";
    for (size_t i = 0; i < imgTote.size(); i++) 
    {
        if (i == 0){ 
            avgImg = cv::Mat::zeros(height, width, CV_64FC3); 
        }

        cout << "Processing...\n";
        cv::accumulate(imgTote[i], avgImg);
    }
    avgImg = (1.0 / num) * avgImg;
    cv::Mat img;
    //avgImg.convertTo(img, CV_8U);

    //cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE); //* Create a window for display
    //cv::imshow("Display window", img);                      //* Show our image inside it
    cv::imwrite("../result.png", avgImg);

    cv::waitKey(0);

    return 0;
}
