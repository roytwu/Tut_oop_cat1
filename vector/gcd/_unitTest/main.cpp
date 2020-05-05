/* *********************************************************
Programmer:  Roy Wu
Description: 
********************************************************* */
#include <iostream>
#include <string>
#include <vector>
#include <Eigen/Core>              //* this needs to added before <opencv2/core/eigen.hpp>
#include <Eigen/Dense>             //* Eigen library: Matrix
#include <Eigen/Geometry>          //* Eigen library: quaternion
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp> 
#include "gcd.hpp"                 //* test target
//#include <boost/algorithm/string.hpp>
//using std::cout; 
//using std::endl;
//using std::string; 
//using std::vector;

#define BOOST_TEST_MODULE testGCD
//#include <boost/test/unit_test.hpp>        //* not working (?)
#include <boost/test/included/unit_test.hpp> //* this works


BOOST_AUTO_TEST_CASE(my_test)
{
    //* 1st test case, 5 elements
    int testArr1[] = { 4, 9, 40, 5, 67 };
    
    //* 2nd test cases, 6 elements
    int testArr2[] = {16, 12, 4, 80, 52, 84};
    
    //* 3rd test cases, 7 elements
    int testArr3[] = {30, 15, 35, 75, 10, 20, 100 };
    


    //* ---seven ways to detect and report the same error:
    BOOST_CHECK(findGCD(2, 2) == 4);          //* #1 continues on error

    BOOST_REQUIRE(add(2, 2) == 4);        //* #2 throws on error

    if (add(2, 2) != 4)
        BOOST_ERROR("Ouch...");           //* #3 continues on error

    if (add(2, 2) != 4)
        BOOST_FAIL("Ouch...");            //* #4 throws on error

    //if (add(2, 2) != 4) throw "Ouch...";  //* #5 throws on error

    //BOOST_CHECK_MESSAGE(add(2, 2) == 4,   //* #6 continues on error
    //    "add(..) result: " << add(2, 2));

    //BOOST_CHECK_EQUAL(add(2, 2), 4);	  //* #7 continues on error
}