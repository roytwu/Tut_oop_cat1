#define BOOST_TEST_MODULE _MySeq
#include <boost/test/included/unit_test.hpp> //* this works
#include "../MySeq.hpp"                      //* including the test object

BOOST_AUTO_TEST_CASE(constructor_test)
{
    MySeq<> test;
    BOOST_CHECK(test.testInt, 100);          //* #1 continues on error
}