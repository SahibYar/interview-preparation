//
// Created by sahib yar on 10/31/17.
//

/*
 * Write a C++ function that takes an array containing the set of all integers
 * in the range 1 to 52 and shuffles it into random order. Use the built-in function
 * rand, which returns a pseudo-random integer each time it is called.
 * Your function should output each possible order with equal probability.
 */

#include <iostream>
#include <iterator>
#include <ctime>        // for time(NULL)
#include <cstdlib>
#include <iterator>
#include <algorithm>
using namespace std;

/*
 * I am creating a function, for shuffling the array, the above statement
 * says that print each possible order, which will be about 52!, so I am just
 * restricting the results to 10.
 */

// shuffle the whole array with equal probability
void shuffle(int a[], int length, int min_range, int max_range)
{
    srand(time(NULL));

    for (int i=0; i < length; i++) {
        int r = rand();
        double d = (double)r / RAND_MAX;
        int range = max_range - min_range + 1;
        int index = d * range;
        std::swap(a[i], a[index]);
    }
}

void print_array(int a[], int length)
{
    for (int i=0; i < length; i++)
        cout << a[i] << " ";
    cout << "\n\n";
}

int main()
{
    int const length = 52;
    int arr[length];
    for (int i =0; i < length; i++)
        arr[i] = i+1;

    for (int i = 0; i < 10; i++) {
        cout << "Array no. " << (i+1) << endl;
        shuffle(arr, length, 1, length);
        print_array(arr, length);
    }
    return EXIT_SUCCESS;
}