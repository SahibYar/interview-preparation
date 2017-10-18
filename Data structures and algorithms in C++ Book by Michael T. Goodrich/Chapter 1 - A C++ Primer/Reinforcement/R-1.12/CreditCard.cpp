//
// Created by Sahib Yar on 10/8/17.
//

#include "CreditCard.h"
using namespace std;

/*
 * Modify the CreditCard class from Code Fragment 1.3 to check that the
 * price argument passed to function chargeIt and the payment argument
 * passed to function makePayment are positive.
 */

bool CreditCard::chargeIt(double price) {
    if (price < 0)
        return false;

    if (price + balance > static_cast<double>(limit))
        return false;
    balance+= price;
    return true;
}

void CreditCard::makePayment(double payment) {
    if (payment < 0)
        return;
    balance -= payment;
}

ostream& operator<<(ostream& out, const CreditCard& c)
{
    out << "Number = "  <<  c.getNumber()    << "\n"
        << "Name = "    <<  c.getName()      << "\n"
        << "Balance = " <<  c.getBalance()   << "\n"
        << "Limit = "   <<  c.getLimit()        << "\n";
    return out;
}
