//
// Created by Sahib Yar on 10/30/17.
//

/*
 * Write a pseudo-code description of a method that reverses an array of n
integers, so that the numbers are listed in the opposite order than they were
before, and compare this method to an equivalent C++ method for doing
the same thing.
 */
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void myreverse(int a[], int length)
{
    int orignal_length = length -1;
    for (int forward_pointer=0, backward_pointer = orignal_length;
         forward_pointer < length / 2;
         forward_pointer++, backward_pointer--)
    {
        int temp = a[forward_pointer];
        a[forward_pointer] = a[backward_pointer];
        a[backward_pointer] = temp;
    }
}

int main()
{
    int a[] = {1,2,3,4,5};
    cout << "Using custom reverse function" << endl;
    myreverse(a, 5);
    for (int i=0; i < 5; i++)
        cout << a[i] << " ";

    cout << "\nUsing std::reverse function" << endl;
    std::reverse(std::begin(a), std::end(a));
    for (int i=0; i < 5; i++)
        cout << a[i] << " ";

    return 0;
}
/*
 * from http://en.cppreference.com/w/cpp/algorithm/reverse it seems that
 * both are equally in terms of time complexity but as I am actually doing the
 * swap of the data but std::reverse is doing pointer swap, this could increase
 * std::reverse speed in general. but this was just for integers, the difference should
 * be insignificant.
 * */