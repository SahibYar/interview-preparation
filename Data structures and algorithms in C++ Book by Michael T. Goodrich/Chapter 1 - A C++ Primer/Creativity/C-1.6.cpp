//
// Created by sahib yar on 10/31/17.
//

/*
 * Write a short C++ program that outputs all possible strings formed by
 * using each of the characters ’a’, ’b’, ’c’, ’d’, ’e’, and ’f’ exactly
 * once.
 */

#include <iostream>
#include <string>
#include <set>
using namespace std;

///
/// \param alreadyChosen
/// \param remaining
/// \param alreadyPrinted  for checking if the string is already printed or not.
void permuteHelper(string alreadyChosen, string remaining, set<string> alreadyPrinted)
{
    if (!remaining.length() &&
            alreadyPrinted.find(alreadyChosen) == alreadyPrinted.end()) {
        cout << alreadyChosen << endl;
        alreadyPrinted.insert(alreadyChosen);
    }
    else
    {
        /*
         * Back Tracking Steps:
         * 1. Choose    (what we are sending forward)
         * 2. Compute   (call yourself)
         * 3. Un-choose (what we are sending backward, etc to the previous calls)
         */
        for (int i = 0; i < remaining.length(); ++i) {
            // choose
            char c = remaining[i];
            remaining.erase(i, 1);
            alreadyChosen += c;

            // compute
            permuteHelper(alreadyChosen, remaining, alreadyPrinted);

            // un-choose
            alreadyChosen.erase(alreadyChosen.length() -1, 1);
            remaining.insert(i, string(1, c));
        }
    }
}

void permute(string s)
{
    set<string> alreadyPrinted;
    permuteHelper("", s, alreadyPrinted);
}

int main()
{
    string s = "abcdef";
    permute(s);
    return EXIT_SUCCESS;
}