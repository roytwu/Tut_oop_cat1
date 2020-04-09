#define BOOST_TEST_MODULE _MySeq
#include <boost/test/included/unit_test.hpp> //* this works
#include "../MySeq.hpp"                      //* including the test object

MySeq<unsigned int, 7> test;

BOOST_AUTO_TEST_CASE(constructor_test)
{
    
    BOOST_CHECK(test.testInt, 100);         
}
