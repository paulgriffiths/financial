/*
 *  test_discount_factor.cpp
 *  ========================
 *  Copyright 2013 Paul Griffiths
 *  Email: mail@paulgriffiths.net
 *  
 *  Unit tests for discount_factor() function.
 *
 *  Uses Boost unit testing framework.
 *  
 *  Distributed under the terms of the GNU General Public License.
 *  http://www.gnu.org/licenses/
 */

#include <boost/test/unit_test.hpp>
#include "../basic_financial.h"

BOOST_AUTO_TEST_SUITE(df_suite)

BOOST_AUTO_TEST_CASE(df_test1) {
    const double tolerance = 0.00001;
    const double expected_result = 0.9759001;
    const double test_result = financial::discount_factor(0.5, 0.05);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(df_test2) {
    const double tolerance = 0.00001;
    const double expected_result = 0.9523810;
    const double test_result = financial::discount_factor(1, 0.05);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(df_test3) {
    const double tolerance = 0.00001;
    const double expected_result = 0.9294286;
    const double test_result = financial::discount_factor(1.5, 0.05);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(df_test4) {
    const double tolerance = 0.00001;
    const double expected_result = 0.9070295;
    const double test_result = financial::discount_factor(2, 0.05);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(df_test5) {
    const double tolerance = 0.00001;
    const double expected_result = 0.8851701;
    const double test_result = financial::discount_factor(2.5, 0.05);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_SUITE_END()
