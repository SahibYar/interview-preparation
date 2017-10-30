//
// Created by developers on 10/31/17.
//

/*
 * Write a C++ function that takes an STL vector of int values and determines
 * if all the numbers are different from each other (that is, they are distinct).
 */

/*
 * I can think of 2 Approaches to solve this problem.
 * 1st Approach:
 *      Brute Force: compare each element with others.
 *      Time complexity = O(n^2)
 * 2nd Approach:
 *      Sort the vector in ascending order.
 *      compare ith element with (i+1)th element
 *      Time Complexity = O(n)
 *      - Sorting may take some additional time
 *        which is minimum O(nlogn)
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool is_distinct_v1(vector<int> a)
{
    if (a.size() < 2)
        return true;

    std::sort(a.begin(), a.end());  // O(n log n)
    for (auto i = a.begin(), j = a.begin() + 1;
         i != a.end() - 1; i++, j++)
        if (*i == *j)
            return false;

    return true;
}

// fancy version
bool is_distinct_v2(vector<int> a)
{
    std::sort(a.begin(), a.end());  // O(n log n)
    return std::adjacent_find(a.begin(), a.end()) == a.end();
}

int main()
{
    vector<int> a = {1,2,3,4,5};
    cout << "is Distinct = " << is_distinct_v1(a) << endl;
    cout << "is Distinct = " << is_distinct_v2(a) << endl;

    return EXIT_SUCCESS;
}