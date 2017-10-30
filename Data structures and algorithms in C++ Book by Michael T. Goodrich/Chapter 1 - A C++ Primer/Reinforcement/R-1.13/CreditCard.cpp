//
// Created by Sahib Yar on 10/19/17.
//

/*
 * Modify the CreditCard class from Code Fragment 1.2 to charge interest
 * on each payment.
 */

#include "CreditCard.h"     // provide CreditCard
using namespace std;

CreditCard::CreditCard(const std::string &no, const std::string &nm, int lim, double bal):
    number(no), name(nm), balance(bal), limit(lim){ }

double CreditCard::chargeInterest(double payment) {
    // for demo, charging a fixed interest of 0.3%
    return payment * 0.003;
}
bool CreditCard::chargeIt(double price)
{
    if (price + balance >  double(lmit))    // over limit
        return false;
    balance += price;
    return true;
}

void CreditCard::makePayment(double payment) {
    balance -= chargeInterest(payment);
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