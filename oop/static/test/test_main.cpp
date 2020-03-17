#define BOOST_TEST_MODULE Account
#include <boost/test/included/unit_test.hpp> //* this works
#include "../account.h"                      //* including the test object

BOOST_AUTO_TEST_CASE(constructor_test)
{
    Account test;
    BOOST_CHECK(test.amount, 100);          //* #1 continues on error
}