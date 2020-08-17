//
// https://leetcode.com/problems/palindrome-number/
//

#include <limits>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        if (x / 10 == 0)
            return true;

        int input_number = x;

        int reverse_number = 0;
        while (input_number > 0) {
            if (reverse_number * 10 > std::numeric_limits<int>::max())
                return false;
            reverse_number = (reverse_number * 10) + (input_number % 10);
            input_number /= 10;
        }

        return x == reverse_number;
    }
};

#include <iostream>

int main() {
    Solution s;
    std::cout << std::boolalpha;

    std::cout << s.isPalindrome(1000) << std::endl;
    std::cout << s.isPalindrome(1001001) << std::endl;
    std::cout << s.isPalindrome(-1001001) << std::endl;
    std::cout << s.isPalindrome(std::numeric_limits<int>::max()) << std::endl;
    std::cout << s.isPalindrome(1) << std::endl;
}