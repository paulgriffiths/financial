/*!
 * \file        basic_dcf.h
 * \brief       Basic discounted cash flow functions.
 * \details     Basic discounted cash flow functions, including for
 * calculating present and future values, values of perpetuities and
 * annuities, loan repayments and sinking fund payments.
 * \author      Paul Griffiths
 * \copyright   Copyright 2013 Paul Griffiths. Distributed under the terms
 * of the GNU General Public License. <http://www.gnu.org/licenses/>
 */

#ifndef PG_FINANCIAL_FUNCTIONS_H
#define PG_FINANCIAL_FUNCTIONS_H

#include <vector>
#include "common_financial_types.h"

//! User library namespace
namespace financial {

//! Calculates a compounding factor.
/*!
 * A compound factor is a number which, when multiplied by an initial
 * investment, will yield the value of that investment after a specified
 * number of periods at a specific interest rate. 
 *
 * For instance, $100 invested for two years at an interest rate of 5%
 * per year will be worth $100 * 1.05 = $105 after the first year, and
 * $105 * 1.05 = $110.25 at the end of the second year. The compound
 * factor for two periods at 5% per period is therefore 110.25 / 100.0 =
 * 1.1025, since $100 * 1.1025 = $110.25.
 *
 * Sample usage:
 * ~~~~{.cpp}
 * double cf = financial::compound_factor(0.1, 7);
 * std::cout << "The value of $100 invested today after 7 "
 *           << "years at an annual interest rate of 10% wil be $"
 *           << 100 * cf << std::endl;
 * ~~~~
 *
 * \param interest_rate the periodic interest rate.
 * \param num_periods the number of periods over which to compound.
 * \param dt the type of compounding to use.
 * \return the calculated compounding factor.
 */

double compound_factor(const double interest_rate,
                       const double num_periods = 1,
                       const enum disc_type dt = disc_type::discrete);

//! Calculates a discount factor.
/*!
 * A discount factor is a number which, when multiplied by a future
 * amount, will yield the value of the investment which, if invested today
 * for a specified number of periods at a specific interest rate, will
 * be worth that future amount.
 *
 * For instance, $100 invested for two years at an interest rate of 5%
 * per year will be worth $100 * 1.05 = $105 after the first year, and
 * $105 * 1.05 = $110.25 at the end of the second year. The discount
 * factor for two periods at 5% per period is therefore 100.0 / 110.25 =
 * 0.90703, since $110.25 * 0.90703 = $100.
 *
 * Sample usage:
 * ~~~~{.cpp}
 * double df = financial::discount_factor(0.12, 4);
 * std::cout << "The value of $1000 received in 4 years time "
 *           << " is " << 1000 * df << " today, assuming an "
 *           << "annual interest rate of 12%." << std::endl;
 * ~~~~
 *
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
 * Present value is a concept related to the time value of money, which
 * states that an amount of money today is worth more than the same amount
 * of money in the future, as a result of investment opportunities available
 * which themselves arise from the fact that, all else being equal,
 * consumption now is preferred to consumption at a future date.
 *
 * For instance, if money can be invested at an interest rate of 5% per
 * year, then $100 invested today will be worth $100 * 1.05 = $105 in one
 * year's time. If given a choice between receiving $100 today or $104
 * in one year's time, therefore, a rational person would choose to receive
 * $100 today, since by investing it she can receive $105 in one year's time
 * rather than $104 in one year's time. In other words, under these conditions,
 * $100 today is worth more than $105 in one year's time, and the present
 * value of $105 received in one year's time is $100.
 *
 * Sample usage:
 * ~~~~{.cpp}
 * double pval = financial::pv(1000, 0.12, 4);
 * std::cout << "The value of $1000 received in 4 years time "
 *           << " is " << pval << " today, assuming an annual "
 *           << "interest rate of 12%." << std::endl;
 * ~~~~
 *
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
 * Future value is a concept related to the time value of money, which
 * states that an amount of money today is worth more than the same amount
 * of money in the future, as a result of investment opportunities available
 * which themselves arise from the fact that, all else being equal,
 * consumption now is preferred to consumption at a future date.
 *
 * For instance, if money can be invested at an interest rate of 5% per
 * year, then $100 invested today will be worth $100 * 1.05 = $105 in one
 * year's time. If given a choice between receiving $99 today or $105
 * in one year's time, therefore, a rational person would choose to receive
 * $105 in one year's time, since foregoing the opportunity to receive
 * $99 in return for a future payment is equivalent to investing $99 today,
 * which would yield only $99 * 1.05% = $103.95, less than $105. In other
 * words, under these conditions, $105 in one year's time is worth more than
 * $99 today, and the future value of $100 today is $105 in one year's time.
 *
 * Sample usage:
 * ~~~~{.cpp}
 * double fval = financial::fv(100, 0.1, 7);
 * std::cout << "The value of $100 invested today after 7 "
 *           << "years at an annual interest rate of 10% wil be $"
 *           << fval << std::endl;
 * ~~~~
 *
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
 * A perpetuity is a periodic cash flow received from now until the
 * end of time. Although at first glance this may seem to have infinite
 * value, the time value of money causes the present value of each cash
 * flow to approach zero as the time period increases, so a perpetuity
 * does have a finite value, equal - for an immediate perpetuity, where
 * the first periodic payment is received at the end of the current period,
 * rather than at the beginning - to the periodic cash flow divided
 * by the interest rate.
 *
 * \param cashflow the nominal amount of the periodic cash flow
 * \param interest_rate the periodic interest rate
 * \param at the type of perpetuity
 * \return the present value of the perpetuity
 */

double pv_perpetuity(const double cashflow,
                     const double interest_rate,
                     const enum annuity_type at = annuity_type::immediate);

//! Calculates the present value of an annuity.
/*!
 * An annuity is a periodic cash flow received for a specified period
 * of time (in reality, many annuities are received in the form of
 * life annuities, where payments continue until the death of the
 * holder, and the period is therefore not fully specified, causing
 * the issuing financial institution to bear some mortality risk).
 * The present value of an annuity is equal to the present value of
 * a perpetuity under the same terms, less the present value of an
 * perpetuity starting at the end of the annuity's payout period.
 *
 * \param cashflow the nominal amount of the periodic cash flow
 * \param interest_rate the periodic interest rate
 * \param num_periods the number of periodic cash flows
 * \param at the type of annuity
 * \return the present value of the annuity
 */

double pv_annuity(const double cashflow,
                  const double interest_rate,
                  const int num_periods,
                  const enum annuity_type at = annuity_type::immediate);

//! Calculates the present value of a stream of cash flows.
/*!
 * Just as the present value of a single payment can be calculated, so
 * can the present value of a stream of timed payments. This technique
 * is often used for valuing financial instruments with regular payouts,
 * and for valuing investment opportunities more generally.
 *
 * \param cashflows a std::vector of TimedCashFlow structs representing
 * the stream of cash flows.
 * \param interest_rate the periodic interest rate
 * \return the present value of the stream of cash flows.
 */

double pv_stream(const std::vector<TimedCashFlow>& cashflows,
                 const double interest_rate);

//! Calculates the periodic payment to a sinking fund.
/*!
 * A sinking fund is an investment which is designed to equal a specific
 * future value at a specified point in time. It is often used as a fund
 * to pay off a known future liability such as a corporate bond maturity,
 * and a retirement fund aiming to provide a particular amount for retirement
 * is analagous. The principal problem with sinking funds is calculating,
 * given the amount of time to termination and an assumption of interest
 * rates, the amount of the periodic payment which must be made to cause
 * the terminal value of the fund to equal the desired future amount.
 *
 * Example of usage:
 * ~~~~{.cpp}
 * double sfp = financial::sinking_fund_payment(10000, 0.05, 5);
 * std::cout << "To achieve a fund value of $10,000 in 5 years at "
 *              "5% per year, you must invest " << sfp
 *              " dollars at the end of each year." << std::endl;
 * ~~~~
 *
 * \param fund_value the terminal value of the sinking fund
 * \param interest_rate the periodic interest rate
 * \param num_periods the number of periodic payments
 * \return the nominal amount of the required periodic payment
 */

double sinking_fund_payment(const double fund_value,
                            const double interest_rate,
                            const double num_periods);

//! Calculates the periodic repayment of a loan.

/*!
 * A loan continues to accrue interest on the outstanding principal
 * even while periodic repayments are being made. The principal problem
 * is calculating, given the time to repayment and an interest rate
 * assumption, the periodic payment that must be made in order to pay
 * off the entire principal and any interest accrued over the life of
 * the loan by the payoff date.
 *
 * ~~~~{.cpp}
 * double month_rate = std::pow(1.0425, 1/12) - 1;
 * double lp = financial::loan_repayment(250000, month_rate, 360);
 * std::cout << "To pay off a $250,000 mortgage after 30 "
 *           << "years at a 4.25% annual interest rate, you "
 *           << "will need to make 360 monthly payments of $"
 *           << lp << " per month." << std::endl;
 * ~~~~
 *
 * \param loan_amount the amount of the loan
 * \param interest_rate the periodic interest rate
 * \param num_periods the number of periodic repayments
 * \return the nominal amount of the periodic loan repayment
 */

double loan_repayment(const double loan_amount,
                      const double interest_rate,
                      const double num_periods);

}               //  namespace financial

#endif          //  PG_FINANCIAL_FUNCTIONS_H
