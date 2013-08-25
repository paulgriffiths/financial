/*
 *  test_simple_bond.cpp
 *  ====================
 *  Copyright 2013 Paul Griffiths
 *  Email: mail@paulgriffiths.net
 *  
 *  Unit tests for simple bonds.
 *
 *  Uses Boost unit testing framework.
 *  
 *  Distributed under the terms of the GNU General Public License.
 *  http://www.gnu.org/licenses/
 */

#include <boost/test/unit_test.hpp>
#include "../bond.h"

BOOST_AUTO_TEST_SUITE(simple_bond_suite)

BOOST_AUTO_TEST_CASE(simple_bond_test1) {
    const double tolerance = 0.0000001;
    const double expected_result = 4000;
    const financial::SimpleBond bond(4000, 0.05, 1, 5);
    const double test_result = bond.value(0.05);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(simple_bond_test2) {
    const double tolerance = 0.0000001;
    const double expected_result = 2961.911306;
    const financial::SimpleBond bond(2500, 0.075, 2, 20);
    const double test_result = bond.value(0.06);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_CASE(simple_bond_test3) {
    const double tolerance = 0.0000001;
    const double expected_result = 4187.960827;
    const financial::SimpleBond bond(7500, 0, 0, 10);
    const double test_result = bond.value(0.06);
    BOOST_CHECK_CLOSE(expected_result, test_result, tolerance);
}

BOOST_AUTO_TEST_SUITE_END()
