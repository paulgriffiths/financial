/*
 *  basic_financial.h
 *  =================
 *  Copyright 2013 Paul Griffiths
 *  Email: mail@paulgriffiths.net
 *  
 *  Interface to basic financial functions.
 *  
 *  Distributed under the terms of the GNU General Public License.
 *  http://www.gnu.org/licenses/
 */

#ifndef PG_FINANCIAL_FUNCTIONS_H
#define PG_FINANCIAL_FUNCTIONS_H

namespace financial {

double discount_factor(const double num_periods,
                       const double discount_rate_per_period);
double present_value(const double cashflow,
                     const double num_periods,
                     const double discount_rate_per_period);
double future_value(const double cashflow,
                    const double num_periods,
                    const double discount_rate_per_period);

}               //  namespace finance

#endif          //  PG_FINANCIAL_FUNCTIONS_H
