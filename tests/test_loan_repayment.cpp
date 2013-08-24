/*
 *  test_loan_repayment.cpp
 *  =======================
 *  Copyright 2013 Paul Griffiths
 *  Email: mail@paulgriffiths.net
 *  
 *  Unit tests for sinking fund payment function.
 *
 *  Uses Boost unit testing framework.
 *  
 *  Distributed under the terms of the GNU General Public License.
 *  http://www.gnu.org/licenses/
 */

#include <boost/test/unit_test.hpp>
#include "../basic_dcf.h"

BOOST_AUTO_TEST_SUITE(loan_repayment_suite)

BOOST_AUTO_TEST_CASE(loan_repayment_test1) {
    const double tolerance = 0.0000001;
    const double expected_result = 643.698094;
    const double test_result = financial::loan_repayment(80000, 0.0075,
            360);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_SUITE_END()
