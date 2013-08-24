/*
 *  test_future_value.cpp
 *  =====================
 *  Copyright 2013 Paul Griffiths
 *  Email: mail@paulgriffiths.net
 *  
 *  Unit tests for fv() function.
 *
 *  Uses Boost unit testing framework.
 *  
 *  Distributed under the terms of the GNU General Public License.
 *  http://www.gnu.org/licenses/
 */

#include <boost/test/unit_test.hpp>
#include "../basic_financial.h"

BOOST_AUTO_TEST_SUITE(fv_suite)

BOOST_AUTO_TEST_CASE(fv_test1) {
    const double tolerance = 0.000001;
    const double expected_result = 102.469508;
    const double test_result = financial::fv(100, 0.05, 0.5);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(fv_test2) {
    const double tolerance = 0.000001;
    const double expected_result = 105;
    const double test_result = financial::fv(100, 0.05, 1);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(fv_test3) {
    const double tolerance = 0.000001;
    const double expected_result = 107.592983;
    const double test_result = financial::fv(100, 0.05, 1.5);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(fv_test4) {
    const double tolerance = 0.000001;
    const double expected_result = 110.25;
    const double test_result = financial::fv(100, 0.05, 2);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(fv_test5) {
    const double tolerance = 0.000001;
    const double expected_result = 112.972632;
    const double test_result = financial::fv(100, 0.05, 2.5);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_SUITE_END()
