//
// https://leetcode.com/problems/string-to-integer-atoi/
//

#include <iomanip>
#include <string_view>
#include <limits>

class Solution {
public:
    int myAtoi(const std::string_view str) {
        int64_t result = 0;
        int sign = 1;
        int i = 0;

        while (str[i] == ' ')
            ++i;

        if (str[i] == '-')
            sign = -1;

        if (str[i] == '-' or str[i] == '+')
            ++i;

        while (i < str.length()) {
            if (isdigit(str[i])) {
                if (result * 10 * sign > std::numeric_limits<int>::max())
                    return std::numeric_limits<int>::max();
                else if (result * 10 * sign < std::numeric_limits<int>::min())
                    return std::numeric_limits<int>::min();
                else
                    result = (result * 10) + (static_cast<int>(str[i]) - 48);
                ++i;
            }
            else
                break;
        }
        result *= sign;

        if (result > std::numeric_limits<int>::max())
            return std::numeric_limits<int>::max();
        else if (result < std::numeric_limits<int>::min())
            return std::numeric_limits<int>::min();
        else
            return result;
    }
};

#include <iostream>

int main() {
    Solution s;

    std::cout << s.myAtoi("0-1") << std::endl;
    std::cout << s.myAtoi("-200000000057948573985739458934340000000000") << std::endl;
    std::cout << s.myAtoi("   +0 123") << std::endl;
    std::cout << s.myAtoi("+-2") << std::endl;
    std::cout << s.myAtoi("++2") << std::endl;
    std::cout << s.myAtoi("-1-1") << std::endl;
    std::cout << s.myAtoi("+4+4") << std::endl;
    std::cout << s.myAtoi("+1") << std::endl;
    std::cout << s.myAtoi("1+") << std::endl;
    std::cout << s.myAtoi("+10001") << std::endl;
    std::cout << s.myAtoi("5050") << std::endl;
    std::cout << s.myAtoi("1000") << std::endl;
    std::cout << s.myAtoi("-964632435") << std::endl;
    std::cout << s.myAtoi("1534236469") << std::endl;
    std::cout << s.myAtoi("    153 4236 9") << std::endl;
    std::cout << s.myAtoi("-  456  90") << std::endl;
    std::cout << s.myAtoi("-  4-56  90") << std::endl;
    std::cout << s.myAtoi("words and 987") << std::endl;
    std::cout << s.myAtoi("4193 with words") << std::endl;
    std::cout << s.myAtoi("-91283472332") << std::endl;
}