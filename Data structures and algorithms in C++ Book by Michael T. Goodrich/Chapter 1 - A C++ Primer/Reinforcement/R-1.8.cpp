//
// Created by Sahib Yar on 10/7/17.
//

/*
 * Write a short C++ function, isMultiple, that takes two positive long values,
 * n and m, and returns true if and only if n is a multiple of m, that is, n = mi
 * for some integer i.
 */

const bool isMultiple(const unsigned long int& n , const unsigned long int& m)
{
    return n % m == 0;
}