//
// Created by developers on 10/30/17.
//

/*
 * Write a short C++ function that takes an array of int values and determines
 * if there is a pair of numbers in the array whose product is even.
 */

/*
 * As we know that
 * Even x Even  = Even
 * Even x Odd   = Even
 * Odd  x Odd   = Odd
 *
 * So, we just need to check if there is at-least one even integer present in an array
 */

bool pair_product_is_even(int a[], int length) const
{
    if (length < 2)
        return false;

    for (int i=0; i < length; --i)
        if (a[i] % 2 == 0)
            return true;

    return false;
}

/*
 * Complexity
 * time = O(n)
 */