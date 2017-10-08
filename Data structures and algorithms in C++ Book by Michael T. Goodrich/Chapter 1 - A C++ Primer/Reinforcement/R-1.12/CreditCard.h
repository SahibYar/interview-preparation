//
// Created by developers on 10/8/17.
//

#ifndef CREDITCARD_H
#define CREDITCARD_H


#include <string>
#include <iostream>

class CreditCard {
private:
    std::string number;
    std::string name;
    int limit;
    double balance;

public:
    CreditCard(const std::string &no, const std::string &nm, const int &lim, const double &bal = 0) :
            number(no), name(nm), limit(lim), balance(bal) {}

    const std::string &getNumber() const {
        return number;
    }

    const std::string &getName() const {
        return name;
    }

    const double &getBalance() const {
        return balance;
    }

    const int &getLimit() const {
        return limit;
    }

    bool chargeIt(double price);

    void makePayment(double payment);
};

std::ostream &operator<<(std::ostream &out, const CreditCard &c);

#endif //CREDITCARD_H
