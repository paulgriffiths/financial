/*!
 * \file        bond.cpp
 * \brief       Bond classes and functions implementation.
 * \details     Bond classes and functions implementation.
 * \author      Paul Griffiths
 * \copyright   Copyright 2013 Paul Griffiths. Distributed under the terms
 * of the GNU General Public License. <http://www.gnu.org/licenses/>
 */

#include <cmath>
#include "common_financial_types.h"
#include "basic_dcf.h"
#include "bond.h"

using namespace financial;

double SimpleBond::value(const double discount_rate) const {
    double ret_value = 0;

    if ( m_coupon_frequency ) {
        std::vector<TimedCashFlow> tcf;
        const double cpymt = m_principal * m_coupon / m_coupon_frequency;
        const double periods = num_payments();
        for ( int cp = 1; cp <= periods; ++cp ) {
            tcf.push_back(TimedCashFlow(cpymt, cp));
        }
        tcf.push_back(TimedCashFlow(m_principal, periods));

        const double pdr = std::pow(1 + discount_rate,
                                    1.0 / m_coupon_frequency) - 1;
        ret_value = pv_stream(tcf, pdr);
    } else {
        ret_value = pv(m_principal, discount_rate, m_maturity);
    }

    return ret_value;
}

double SimpleBond::num_payments() const {
    if ( m_coupon_frequency ) {
        return m_maturity * m_coupon_frequency;
    } else {
        return 1;
    }
}
