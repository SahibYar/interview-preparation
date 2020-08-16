//
// https://leetcode.com/problems/reverse-integer/
//

#include <cstdint>
#include <limits>

class Solution {
public:
    int reverse(int x) {
        int64_t result = 0;
        int input = x;
        while (input != 0) {
            result = result * 10 + input % 10;
            input /= 10;
        }
        // to avoid runtime error: signed integer overflow
        if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
            return 0;
        else
            return result;
    }
};

#include <iostream>

int main() {
    Solution s;
    std::cout << s.reverse(1) << std::endl;
    std::cout << s.reverse(10001) << std::endl;
    std::cout << s.reverse(5050) << std::endl;
    std::cout << s.reverse(1000) << std::endl;
    std::cout << s.reverse(-964632435) << std::endl;
    std::cout << s.reverse(1534236469) << std::endl;

}