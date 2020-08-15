//
// https://leetcode.com/problems/zigzag-conversion/
//

#include <string>
class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows < 2)
            return s;

        std::string result[numRows];

        int i = 0;
        bool increment = true;
        for (const auto &c : s) {
            result[i].push_back(c);

            if (increment)
                ++i;
            else
                --i;

            if ((i+1) == numRows)
                increment = false;
            if(i == 0)
                increment = true;
        }

        std::string outstring = "";
        for (const auto &str : result) {
            outstring.append(str);
        }
        return outstring;
    }
};

#include <iostream>

int main() {
    Solution s;
    std::cout << s.convert("PAYPALISHIRING", 3) << std::endl;
    std::cout << s.convert("PAYPALISHIRING", 4) << std::endl;
}