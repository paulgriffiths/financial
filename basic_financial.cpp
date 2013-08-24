/*
 *  basic_financial.cpp
 *  ===================
 *  Copyright 2013 Paul Griffiths
 *  Email: mail@paulgriffiths.net
 *  
 *  Implementation of basic financial functions.
 *  
 *  Distributed under the terms of the GNU General Public License.
 *  http://www.gnu.org/licenses/
 */

#include <cmath>
#include "basic_financial.h"

using namespace financial;

double financial::discount_factor(const double num_periods,
                                  const double discount_rate) {
    return (1 / pow(1 + discount_rate, num_periods));
}


double financial::present_value(const double cashflow,
                                const double num_periods,
                                const double discount_rate) {
    return cashflow * discount_factor(num_periods, discount_rate);
}

double financial::future_value(const double cashflow,
                               const double num_periods,
                               const double discount_rate) {
    return cashflow / discount_factor(num_periods, discount_rate);
}

