//
// Created by Sahib Yar on 10/7/17.
//

/*
Write a pseudo-code description of a method for finding the smallest and
largest numbers in an array of integers and compare that to a C++ function
that would do the same thing.
*/
/*
 * # Assumptions:
 *      we are using native integer as a data type in this array. and array
 *      has at-least one element in it.
 *
 * Pseudo-Code for largest
 *
 * int find_largest(A[])
 * {
 *      if (A.size() == 1)
 *          return A[0];
 *
 *      int largest = A[0];
 *      while (!A.end())
 *      {
 *          if (largest > A[i])
 *            largest = A[i]
 *      }
 *      return largest;
 * }
 */

/*
 * Better Approach
 * Sort it first and then find the largest or smallest, as it is
 * a native integer, So, we can use std::sort for sorting, and them
 *
 * for largest element:
 *          last element of an array
 *
 * for smallest element.
 *          1st element of an array.
 */

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

template <size_t SIZE>
int find_largest1 (array<int, SIZE> &a1)
{
    std::sort(a1.begin(), a1.end());
    return a1.back();
}

template <size_t SIZE>
int find_largest2 (array<int, SIZE> &a1)
{
    std::sort(a1.begin(), a1.end(), std::greater<int>());
    return a1.front();
}

template <size_t SIZE>
int find_smallest (array<int, SIZE> &a1)
{
    std::sort(a1.begin(), a1.end());
    return a1.front();
}

int main() {
    array<int, 10> arr = {1,2,3,4,5,6,7,8,9,13};
    cout << find_largest1(arr) << endl;
    cout << find_largest2(arr) << endl;
    cout << find_smallest(arr) << endl;
    return EXIT_SUCCESS;
}