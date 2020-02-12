/* *********************************************************
File name:   main.cpp (imageStacking)
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
    cv::String folder = "../stackingSample/aligned_png";
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
    cout << "\nFinished reading files...\n";

    //* ---image size
    height = imgTote[0].rows;
    width = imgTote[0].cols;
    //cout << "width is ..."  << width << endl;
    //cout << "height is ..." << height << endl;

    //* --- upsampling 
    std::vector<cv::Mat> imgTote_UP;
    //imgTote_UP.reserve(num);
    for (size_t i = 0; i < imgTote.size(); i++)
    {
        cout << "upsampling...\n";
        cv::Mat imgUP;
        cv::pyrUp(imgTote[i], imgUP, cv::Size(width * 2, height * 2));
        cv::pyrUp(imgUP,      imgUP, cv::Size(width * 4, height * 4));
        imgTote_UP.push_back(imgUP);

        cv::imwrite("../result_upsample.png", imgUP);
        exit;
    }

    int h = imgTote_UP[1].rows;
    int w = imgTote_UP[1].cols;
    //cout << "w is ..."  << w << endl;
    //cout << "h is ..." << h << endl;

    for (size_t i = 0; i < imgTote_UP.size(); i++) 
    {
        if (i == 0){ 
            //avgImg = cv::Mat::zeros(height, width, CV_64FC3); 
            avgImg = cv::Mat::zeros(h, w, CV_64FC3);
        }
        cout << "Processing...\n";
        cv::accumulate(imgTote_UP[i], avgImg);

        //* accessing pixel value
        //cv::Vec3b bgr = imgTote[i].at<cv::Vec3b>(0, 0);
        //cout << bgr << endl;
    }
    avgImg = (1.0 / num) * avgImg;
    //avgImg.convertTo(img, CV_8U);

    //cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE); //* Create a window for display
    //cv::imshow("Display window", img);                      //* Show our image inside it
    cv::imwrite("../result.png", avgImg);

    cv::waitKey(0);

    return 0;
}
