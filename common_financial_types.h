/*!
 * \file        common_financial_types.h
 * \brief       Common types, enums and constants.
 * \details     Common types, enums and constants.
 * \author      Paul Griffiths
 * \copyright   Copyright 2013 Paul Griffiths. Distributed under the terms
 * of the GNU General Public License. <http://www.gnu.org/licenses/>
 */

#ifndef PG_FINANCIAL_COMMON_TYPES_H
#define PG_FINANCIAL_COMMON_TYPES_H

//! User library namespace
namespace financial {

//! Euler's number

/*!
 * Euler's number is the limit of `(1 + 1/n) ** n` as `n` approaches
 * infinity.
 *
 * The exponention *function*, `e ** x`, is the only nontrivial function
 * which is its own derivative, and its own antiderivative too.
 */

const double e = 2.71828182845904523536;

//! Enumeration class for discounting types

/*!
 * Discounting can be done *discretely*, where interest is calculated
 * once every period, or *continuously*, where interest is calculated
 * on a theoretically continual basis. Discrete compounding is far
 * more common in practice.
 */

enum class disc_type {
    discrete,           /*!< discrete compounding. */
    continuous          /*!< continuous compounding. */
};

//! Enumeration class for annuity types

/*!
 * Annuities (and perpetuities) can be *immediate*, where each payment
 * comes at the end of each period, or *due*, where each payment comes
 * at the beginning of each period.
 */

enum class annuity_type {
    immediate,          /*!< immediate annuity, payment at end of period. */
    due                 /*!< due annuity, payment at beginning of period. */
};

//! Timed cash flow structure

/*!
 * The `TimedCashFlow` struct describes both the amount and the timing
 * of a future cash flow.
 */

struct TimedCashFlow {
    double amount;       /*!< the amount of the cash flow */
    double time_period;  /*!< the period at which the cash flow will occur */

    //! Default constructor

    /*!
     * Initializes members to zero.
     */

    explicit TimedCashFlow() : amount(0), time_period(0) {}

    //! Constructor

    /*!
     * Initializes members to provided values.
     *
     * \param amount the amount of the cash flow
     * \param time_period the period at which the cash flow will occur
     */

    explicit TimedCashFlow(const double amount,
                           const double time_period) :
        amount(amount), time_period(time_period) {}
};

}               //  namespace financial

#endif          //  PG_FINANCIAL_COMMON_TYPES_H
