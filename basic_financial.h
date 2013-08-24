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

const double e = 2.71828182845904523536;

enum class disc_type {discrete, continuous};

double discount_factor(const double discount_rate_per_period,
                       const double num_periods = 1,
                       const enum disc_type = disc_type::discrete);
double pv(const double cashflow,
          const double discount_rate_per_period,
          const double num_periods = 1,
          const enum disc_type = disc_type::discrete);
double fv(const double cashflow,
          const double discount_rate_per_period,
          const double num_periods = 1,
          const enum disc_type = disc_type::discrete);

}               //  namespace finance

#endif          //  PG_FINANCIAL_FUNCTIONS_H
