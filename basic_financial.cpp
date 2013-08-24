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

double financial::discount_factor(const double discount_rate,
                                  const double num_periods,
                                  const enum disc_type dt) {
    if ( dt == disc_type::discrete ) {
        return (1 / pow(1 + discount_rate, num_periods));
    } else if ( dt == disc_type::continuous ) {
        return (1 / pow(e, discount_rate * num_periods));
    }

    return 0;
}


double financial::pv(const double cashflow,
                     const double discount_rate,
                     const double num_periods,
                     const enum disc_type dt) {
    return cashflow * discount_factor(discount_rate, num_periods, dt);
}

double financial::fv(const double cashflow,
                     const double discount_rate,
                     const double num_periods,
                     const enum disc_type dt) {
    return cashflow / discount_factor(discount_rate, num_periods, dt);
}

