/*
 *  test_sinking_fund.cpp
 *  =====================
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

BOOST_AUTO_TEST_SUITE(sinking_fund_suite)

BOOST_AUTO_TEST_CASE(sinking_fund_test1) {
    const double tolerance = 0.0000001;
    const double expected_result = 3110.332494;
    const double test_result = financial::sinking_fund_payment(40000, 0.0125,
            12);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_SUITE_END()
