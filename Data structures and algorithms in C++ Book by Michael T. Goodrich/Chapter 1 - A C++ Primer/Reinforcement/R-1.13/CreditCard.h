//
// Created by developers on 10/19/17.
//

#ifndef CREDIT_CARD_H   // avoid repeated expansion
#define CREDIT_CARD_H

#include <iostream>
#include <string>

class CreditCard{
public:
    CreditCard(const std::string& no, const std::string& nm, int lim, double bal=0);

    std::string getNumber() const {
        return number;
    }

    std::string getName() const {
        return name;
    }

    double getBalance() const {
        return balance;
    }

    int getLimit() const {
        return limit;
    }

    bool chargeIt(double price);        // make a charge
    void makePayment(double payment);   // make a payment

private:
    std::string number;     // credit card number
    std::string name;       // card owner's name
    int limit;              // credit limit
    double balance;         // credit card balance
};

std::ostream& operator<<(std::ostream& out, const CreditCard& c);
#endif //CREDIT_CARD_H
