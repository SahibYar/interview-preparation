//
// Created by developers on 10/31/17.
//

/*
 * Write a C++ function that takes an STL vector of int values and prints all
 * the odd values in the vector.
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void print_odd(vector<int> a)
{
    std::sort(a.begin(), a.end());
    for (auto i = a.begin(); i != a.end(); i++)
        if (*i & 1)
            cout << *i << endl;
}

int main()
{
    vector<int> a = {1,2,3,4,5};
    print_odd(a);
    return EXIT_SUCCESS;
}