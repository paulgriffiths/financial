/*
 *  basic_dcf.cpp
 *  =============
 *  Copyright 2013 Paul Griffiths
 *  Email: mail@paulgriffiths.net
 *  
 *  Implementation of basic discounted cash flow functions.
 *  
 *  Distributed under the terms of the GNU General Public License.
 *  http://www.gnu.org/licenses/
 */

#include <vector>
#include <cassert>
#include <cmath>
#include "basic_dcf.h"

using namespace financial;

double financial::compound_factor(const double interest_rate,
                                  const double num_periods,
                                  const enum disc_type dt) {
    if ( dt == disc_type::discrete ) {
        return std::pow(1 + interest_rate, num_periods);
    } else if ( dt == disc_type::continuous ) {
        return std::pow(e, interest_rate * num_periods);
    } else {
        assert(false);
        return 0;
    }
}


double financial::discount_factor(const double interest_rate,
                                  const double num_periods,
                                  const enum disc_type dt) {
    return (1 / compound_factor(interest_rate, num_periods, dt));
}


double financial::pv(const double cashflow,
                     const double interest_rate,
                     const double num_periods,
                     const enum disc_type dt) {
    return cashflow * discount_factor(interest_rate, num_periods, dt);
}

double financial::fv(const double cashflow,
                     const double interest_rate,
                     const double num_periods,
                     const enum disc_type dt) {
    return cashflow * compound_factor(interest_rate, num_periods, dt);
}

double financial::pv_perpetuity(const double cashflow,
                                const double interest_rate,
                                const enum annuity_type at) {
    double present_value = cashflow / interest_rate;
    if ( at == annuity_type::due ) {
        present_value *= compound_factor(interest_rate, 1);
    }
    return present_value;
}

double financial::pv_annuity(const double cashflow,
                             const double interest_rate,
                             const int num_periods,
                             const enum annuity_type at) {
    const double pvp = pv_perpetuity(cashflow, interest_rate, at);
    return pvp * (1 - discount_factor(interest_rate, num_periods));
}

double financial::pv_stream(const std::vector<TimedCashFlow>& cashflows,
                            const double interest_rate) {
    double pv_total = 0;
    for ( std::vector<TimedCashFlow>::const_iterator itr = cashflows.begin();
            itr != cashflows.end(); ++itr ) {
        const TimedCashFlow& cf = *itr;
        pv_total += pv(cf.amount, interest_rate, cf.time_period);
    }
    return pv_total;
}

double financial::sinking_fund_payment(const double fund_value,
                                       const double interest_rate,
                                       const double num_periods) {
    const double factor = (compound_factor(interest_rate, num_periods) - 1) /
                               interest_rate; 
    return fund_value / factor;
}

double financial::loan_repayment(const double loan_amount,
                                 const double interest_rate,
                                 const double num_periods) {
    const double factor = interest_rate /
                        (1 - discount_factor(interest_rate, num_periods));
    return loan_amount * factor;
}

