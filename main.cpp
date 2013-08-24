/*
 *  main.cpp
 *  ========
 *  Copyright 2013 Paul Griffiths
 *  Email: mail@paulgriffiths.net
 *
 *  Sample usage of financial library.
 *
 *  Distributed under the terms of the GNU General Public License.
 *  http://www.gnu.org/licenses/
 */

#include <iostream>
#include <paulgrif/financial.h>

int main(void) {

    const double pv = financial::present_value(100, 1, 0.05);
    std::cout << "PV of 100 in 1 period at 5% is: " << pv << std::endl;

    const double pv2 = financial::present_value(100, 2, 0.05);
    std::cout << "PV of 100 in 2 periods at 5% is: " << pv2 << std::endl;

    const double fv = financial::future_value(pv, 1, 0.05);
    std::cout << "FV of 95.2381 in 1 period at 5% is: " << fv << std::endl;

    const double fv2 = financial::future_value(pv2, 2, 0.05);
    std::cout << "FV of 90.7029 in 2 periods at 5% is: " << fv2 << std::endl;

    return 0;
}
