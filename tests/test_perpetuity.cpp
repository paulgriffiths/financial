/*
 *  test_perpetuity.cpp
 *  ===================
 *  Copyright 2013 Paul Griffiths
 *  Email: mail@paulgriffiths.net
 *  
 *  Unit tests for perpetuity valuations.
 *
 *  Uses Boost unit testing framework.
 *  
 *  Distributed under the terms of the GNU General Public License.
 *  http://www.gnu.org/licenses/
 */

#include <boost/test/unit_test.hpp>
#include "../basic_dcf.h"

BOOST_AUTO_TEST_SUITE(perpetuity_suite)

BOOST_AUTO_TEST_CASE(perpetuity_test1) {
    const double tolerance = 0.000001;
    const double expected_result = 2000;
    const double test_result = financial::pv_perpetuity(100, 0.05);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(perpetuity_test2) {
    const double tolerance = 0.000001;
    const double expected_result = 1000;
    const double test_result = financial::pv_perpetuity(100, 0.1);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(perpetuity_test3) {
    const double tolerance = 0.000001;
    const double expected_result = 500;
    const double test_result = financial::pv_perpetuity(100, 0.2);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(perpetuity_test4) {
    const double tolerance = 0.000001;
    const double expected_result = 200;
    const double test_result = financial::pv_perpetuity(100, 0.5);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(perpetuity_test5) {
    const double tolerance = 0.000001;
    const double expected_result = 100;
    const double test_result = financial::pv_perpetuity(100, 1);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(perpetuity_due_test1) {
    const double tolerance = 0.000001;
    const double expected_result = 2100;
    const double test_result = financial::pv_perpetuity(100, 0.05,
            financial::annuity_type::due);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(perpetuity_due_test2) {
    const double tolerance = 0.000001;
    const double expected_result = 1100;
    const double test_result = financial::pv_perpetuity(100, 0.1,
            financial::annuity_type::due);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(perpetuity_due_test3) {
    const double tolerance = 0.000001;
    const double expected_result = 600;
    const double test_result = financial::pv_perpetuity(100, 0.2,
            financial::annuity_type::due);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(perpetuity_due_test4) {
    const double tolerance = 0.000001;
    const double expected_result = 300;
    const double test_result = financial::pv_perpetuity(100, 0.5,
            financial::annuity_type::due);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(perpetuity_due_test5) {
    const double tolerance = 0.000001;
    const double expected_result = 200;
    const double test_result = financial::pv_perpetuity(100, 1,
            financial::annuity_type::due);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_SUITE_END()
