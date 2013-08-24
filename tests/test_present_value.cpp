/*
 *  test_present_value.cpp
 *  ======================
 *  Copyright 2013 Paul Griffiths
 *  Email: mail@paulgriffiths.net
 *  
 *  Unit tests for present_value() function.
 *
 *  Uses Boost unit testing framework.
 *  
 *  Distributed under the terms of the GNU General Public License.
 *  http://www.gnu.org/licenses/
 */

#include <boost/test/unit_test.hpp>
#include "../basic_financial.h"

BOOST_AUTO_TEST_SUITE(pv_suite)

BOOST_AUTO_TEST_CASE(pv_test1) {
    const double tolerance = 0.000001;
    const double expected_result = 97.590007;
    const double test_result = financial::present_value(100, 0.5, 0.05);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(pv_test2) {
    const double tolerance = 0.000001;
    const double expected_result = 95.238095;
    const double test_result = financial::present_value(100, 1, 0.05);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(pv_test3) {
    const double tolerance = 0.000001;
    const double expected_result = 92.942864;
    const double test_result = financial::present_value(100, 1.5, 0.05);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(pv_test4) {
    const double tolerance = 0.000001;
    const double expected_result = 90.702948;
    const double test_result = financial::present_value(100, 2, 0.05);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(pv_test5) {
    const double tolerance = 0.000001;
    const double expected_result = 88.517013;
    const double test_result = financial::present_value(100, 2.5, 0.05);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_SUITE_END()
