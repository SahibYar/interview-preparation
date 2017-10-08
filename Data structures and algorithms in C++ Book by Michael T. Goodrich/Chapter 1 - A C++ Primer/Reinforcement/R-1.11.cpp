//
// Created by developers on 10/8/17.
//

/*
 * Write a C++ class, Flower, that has three member variables of type string,
 * int, and float, which respectively represent the name of the flower, its
 * number of pedals, and price. Your class must include a constructor method
 * that initializes each variable to an appropriate value, and your class should
 * include functions for setting the value of each type, and getting the value
 * of each type
 */

#include <string>

using namespace std;

class Flower {
private:
    string name;
    int pedals;
    float price;

public:
    explicit Flower() : name(""), pedals(0), price(0.0) {}

    explicit Flower(const string &n, int pd, float pr)
            : name(n), pedals(pd), price(pr) {}

    Flower(const Flower &f) {
        name = f.name;
        pedals = f.pedals;
        price = f.price;
    }

    Flower &operator=(const Flower &f) {
        if (f != *this) {       // handling reference to self.
            name = f.name;
            pedals = f.pedals;
            price = f.price;
        }
        return *this;
    }



    const string& getName() const {
        return name;
    }

    const int& getPedals() const {
        return pedals;
    }

    const float& getPrice() const {
        return price;
    }

    void setName(const string &n) {
        name = n;
    }

    void setPedals(const int &pd) {
        pedals = pd;
    }

    void setPrice(const int &pr) {
        price = pr;
    }
};