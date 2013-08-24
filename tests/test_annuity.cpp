/*
 *  test_annuity.cpp
 *  ================
 *  Copyright 2013 Paul Griffiths
 *  Email: mail@paulgriffiths.net
 *  
 *  Unit tests for annuity valuations.
 *
 *  Also tests pv_stream() function by comparison.
 *
 *  Uses Boost unit testing framework.
 *  
 *  Distributed under the terms of the GNU General Public License.
 *  http://www.gnu.org/licenses/
 */

#include <boost/test/unit_test.hpp>
#include <vector>
#include "../basic_dcf.h"

BOOST_AUTO_TEST_SUITE(annuity_suite)

BOOST_AUTO_TEST_CASE(annuity_test1) {
    const double tolerance = 0.000001;
    const double expected_result = 772.173493;
    const double test_result = financial::pv_annuity(100, 0.05, 10);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(annuity_test2) {
    const double tolerance = 0.000001;

    std::vector<financial::TimedCashFlow> cfs;
    for ( int i = 1; i < 11; ++i ) {
        cfs.push_back(financial::TimedCashFlow(100, i));
    }

    const double expected_result = pv_stream(cfs, 0.05);
    const double test_result = financial::pv_annuity(100, 0.05, 10);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(annuity_due_test1) {
    const double tolerance = 0.000001;
    const double expected_result = 1386.635547;
    const double test_result = financial::pv_annuity(150, 0.08, 15,
            financial::annuity_type::due);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(annuity_due_test2) {
    const double tolerance = 0.000001;

    std::vector<financial::TimedCashFlow> cfs;
    for ( int i = 0; i < 15; ++i ) {
        cfs.push_back(financial::TimedCashFlow(150, i));
    }

    const double expected_result = pv_stream(cfs, 0.08);
    const double test_result = financial::pv_annuity(150, 0.08, 15,
            financial::annuity_type::due);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_SUITE_END()
