/*
 *  common_financial_types.h
 *  ========================
 *  Copyright 2013 Paul Griffiths
 *  Email: mail@paulgriffiths.net
 *  
 *  Common financial types and constants.
 *  
 *  Distributed under the terms of the GNU General Public License.
 *  http://www.gnu.org/licenses/
 */

/*!
 * \file common_financial_types.h
 * \brief Common financial types and constants.
 */

#ifndef PG_FINANCIAL_COMMON_TYPES_H
#define PG_FINANCIAL_COMMON_TYPES_H

namespace financial {

//! Euler's number
const double e = 2.71828182845904523536;

//! Enumeration class for discounting types
enum class disc_type {
    discrete,           /*!< discrete compounding. */
    continuous          /*!< continuous compounding. */
};

//! Enumeration class for annuity types
enum class annuity_type {
    immediate,          /*!< immediate annuity, payment at end of period. */
    due                 /*!< due annuity, payment at beginning of period. */
};

//! Timed cash flow structure
struct TimedCashFlow {
    double amount;
    double time_period;

    explicit TimedCashFlow() : amount(0), time_period(0) {}
    explicit TimedCashFlow(const double amount,
                           const double time_period) :
        amount(amount), time_period(time_period) {}
};

}               //  namespace financial

#endif          //  PG_FINANCIAL_COMMON_TYPES_H
