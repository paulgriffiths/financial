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

//! Basic financial functions
/*!
 * Basic financial functions, including:
 * * present and future value calculations; and
 * * perpetuity and annuity valuations.
 */

#ifndef PG_FINANCIAL_FUNCTIONS_H
#define PG_FINANCIAL_FUNCTIONS_H

#include "common_financial_types.h"

namespace financial {

//! Calculates a discount factor.
/*!
 * \param interest_rate the periodic interest rate.
 * \param num_periods the number of periods over which to discount.
 * \param dt the type of compounding to use.
 * \return the calculated discount factor.
 */

double discount_factor(const double interest_rate,
                       const double num_periods = 1,
                       const enum disc_type dt = disc_type::discrete);

//! Calculates the present value of a single cash flow.
/*!
 * \param cashflow the nominal amount of the single cash flow
 * \param interest_rate the periodic interest rate
 * \param num_periods the number of periods until the cash flow
 * \param dt the type of discounting to use
 * \return the present value of the cash flow
 */

double pv(const double cashflow,
          const double interest_rate,
          const double num_periods = 1,
          const enum disc_type dt = disc_type::discrete);

//! Calculates the future value of a single invested cash flow.
/*!
 * \param cashflow the nominal amount of the invested cash flow
 * \param interest_rate the periodic interest rate
 * \param num_periods the number of periods until maturity
 * \param dt the type of compounding to use
 * \return the future value of the cash flow
 */

double fv(const double cashflow,
          const double interest_rate,
          const double num_periods = 1,
          const enum disc_type = disc_type::discrete);

//! Calculates the present value of a perpetuity
/*!
 * \param cashflow the nominal amount of the periodic cash flow
 * \param interest_rate the periodic interest rate
 * \param at the type of perpetuity
 * \return the future value of the cash flow
 */

double pv_perpetuity(const double cashflow,
                     const double interest_rate,
                     const enum annuity_type at = annuity_type::immediate);

}               //  namespace financial

#endif          //  PG_FINANCIAL_FUNCTIONS_H
