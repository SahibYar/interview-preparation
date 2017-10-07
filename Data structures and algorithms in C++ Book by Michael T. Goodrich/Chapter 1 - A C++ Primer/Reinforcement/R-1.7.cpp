//
// Created by developers on 10/7/17.
//

/*
 * Write a short C++ function that takes an integer n and returns the sum of
 * all the integers smaller than n
 */

/*
 * ASSUMPTIONS:
 *      minimum digit is zero, no negative integer is given as an input.
 *
 * Logic:
 *      (n * (n + 1)) / 2
 */

const int sum_of_n(const int &n)
{
    if (n < 0)
        return EXIT_FAILURE;
    return (n * (n + 1)) / 2;
}