/*!
 * \file        bond.h
 * \brief       Bond classes and functions interface.
 * \details     Bond classes and functions interface.
 * \author      Paul Griffiths
 * \copyright   Copyright 2013 Paul Griffiths. Distributed under the terms
 * of the GNU General Public License. <http://www.gnu.org/licenses/>
 */

#ifndef PG_FINANCIAL_BOND_H
#define PG_FINANCIAL_BOND_H

#include <vector>

//! User library namespace

namespace financial {


//! Simple bond class.

/*!
 * Models a simple bond. Valuation is only possible at issuance.
 * Accrued interest cannot be calculated. Maturity can only be
 * expressed in whole periods.
 */

class SimpleBond {
    public:
        
        //! Constructor

        /*!
         * Constructor.
         *
         * \param principal the principal amount
         * \param coupon the periodic coupon rate
         * \param coupon_frequency the number of coupon payments each period
         * \param maturity the number of periods to maturity
         */

        explicit SimpleBond(const double principal,
                            const double coupon,
                            const int coupon_frequency,
                            const int maturity) :
        m_principal(principal),
        m_coupon(coupon),
        m_coupon_frequency(coupon_frequency),
        m_maturity(maturity) {};


        //! Destructor

        virtual ~SimpleBond() {};


        //! DCF valuation

        /*!
         * Values a simple bond with discounted cash flows.
         *
         * \param discount_rate the discount rate to use.
         * \return the present value of the bond
         */

        double value(const double discount_rate) const;


    private:
        double m_principal;     /*!< principal amount */
        double m_coupon;        /*!< periodic coupon */
        int m_coupon_frequency; /*!< coupon payments per period */
        int m_maturity;         /*!< periods to maturity */


        //! Returns the number of payments over the bond's lifetime.

        /*!
         * The final coupon payment and the return of principal is
         * counted as a single payment, so for zero-coupon bonds
         * this will return 1.
         *
         * \return the number of payments over the bond's lifetime.
         */

        double num_payments() const;
};

}               //  namespace financial

#endif          //  PG_FINANCIAL_BOND_H
