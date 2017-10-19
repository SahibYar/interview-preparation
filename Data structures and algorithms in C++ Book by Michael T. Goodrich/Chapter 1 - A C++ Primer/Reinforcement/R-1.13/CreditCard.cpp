//
// Created by developers on 10/19/17.
//

/*
 * Modify the CreditCard class from Code Fragment 1.3 to check that the
price argument passed to function chargeIt and the payment argument
passed to function makePayment are positive.
 */

#include "CreditCard.h"     // provide CreditCard
using namespace std;

CreditCard::CreditCard(const std::string &no, const std::string &nm, int lim, double bal):
    number(no), name(nm), balance(bal), limit(lim){ }

bool CreditCard::chargeIt(double price)
{
    if (price < 0)
        return false;
    if (price + balance >  double(lmit))    // over limit
        return false;
    balance += price;
    return true;
}

void CreditCard::makePayment(double payment) {
    if (payment < 0)
        return;
    balance -= payment;
}

ostream& operator<<(ostream& out, const CreditCard& c)
{
    out <<  "Number = "  << c.getNumber()    << "\n"
        <<  "Name = "    << c.getName()      << "\n"
        <<  "Balance = " << c.getBalance()   << "\n"
        <<  "Limit = "   << c.getLimit()     << "\n";
    return out;
}