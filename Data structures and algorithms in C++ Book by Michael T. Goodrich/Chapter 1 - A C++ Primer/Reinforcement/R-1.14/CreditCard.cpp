//
// Created by Sahib Yar on 10/19/17.
//

/*
 * Modify the CreditCard class from Code Fragment 1.2 to charge a late fee
 * for any payment that is past its due date.
 */

#include "CreditCard.h"     // provide CreditCard
using namespace std;

CreditCard::CreditCard(const std::string &no, const std::string &nm, int lim, double bal):
        number(no), name(nm), balance(bal), limit(lim){ }

double CreditCard::lateFee(double payment, int noDay) const {
    return payment * 0.001 * noDay;
}

bool CreditCard::chargeIt(double price)
{
    if (price + balance >  double(lmit))    // over limit
        return false;
    balance += price;
    return true;
}

void CreditCard::makePayment(double payment) {
    
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