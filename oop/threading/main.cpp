/* *********************************************************
File name:   main.cpp (algorithm)
Programmer:  Roy Wu
Description: examples of multi-threading
********************************************************* */
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <Eigen/Core>              //* this needs to added before <opencv2/core/eigen.hpp>
#include <Eigen/Dense>             //* Eigen library: Matrix
#include <Eigen/Geometry>          //* Eigen library: quaternion
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp> 
using std::cout; 
using std::endl;
using std::string; 
using std::vector;

void foo(int Z) 
{
    for (int i = 0; i < Z; i++) 
    {
        cout << "pointer as callable\n";
    }
}

class threadObj 
{
public:
    void operator()(int x) 
    {
        for (int i = 0; i < x; i++) 
        {
            cout << "object as callable\n";
        }
    }
};

int main()
{
    std::thread thA(foo, 5);
    std::thread thB(threadObj(), 3);

    thA.join();
    thB.join();

    return 0;
}

