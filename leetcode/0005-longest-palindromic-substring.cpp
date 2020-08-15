//
// https://leetcode.com/problems/longest-palindromic-substring/
//

#include <string>
#include <deque>
#include <iostream>

class Solution {
public:
    bool is_palindrom(const std::string &s) {
        unsigned int i = 0;
        unsigned int j = s.length() - 1;

        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            } else {
                return false;
            }
        }
        return true;
    }

    std::string longestPalindrome(std::string s) {
        if (s.length() < 2) {
            return s;
        }

        if (s.length() == 2) {
            if (is_palindrom(s))
                return s;
            else
                return s.substr(0, 1);
        }

        size_t size_of_dp = s.length() + 1;
        //initializing DP matrix
        int DP[size_of_dp][size_of_dp];
        for (unsigned int i = 0; i < size_of_dp; i++) {
            for (unsigned int j = 0; j < size_of_dp; j++) {
                if (i == j)
                    DP[i][j] = 1;   //string of length 1 will always be palindrom
                else
                    DP[i][j] = 0;
            }
        }

        int max_length = 1;
        size_t palindrom_starting_index = 0;

        for (unsigned int window = 2; window <= s.length(); window++) {
            size_t i = 1;
            size_t j = (i - 1) + window;

            while (j <= s.length()) {

                /*
                 * For substr of size of 2, we have to check for palindrom
                 * For greater sizes we can use DP*/

                if ((window == 2 and is_palindrom(s.substr(i - 1, window))) ||
                    (s[i - 1] == s[j - 1] and DP[i + 1][j - 1] == 1)) {
                    DP[i][j] = 1;
                    if (max_length < window) {
                        max_length = window;
                        palindrom_starting_index = i - 1;
                    }
                }
                ++i;
                j = (i - 1) + window;
            }
        }
        return s.substr(palindrom_starting_index, max_length);
    }
};

int main() {
    Solution s;
    std::cout << s.longestPalindrome("aba") << std::endl;
    std::cout << s.longestPalindrome("aaaabbaa") << std::endl;
    std::cout << s.longestPalindrome("abcabcbb") << std::endl;
    std::cout << s.longestPalindrome("bbbbb") << std::endl;
    std::cout << s.longestPalindrome("pwwkew") << std::endl;
    std::cout << s.longestPalindrome(" ") << std::endl;
    std::cout << s.longestPalindrome("ab") << std::endl;
    std::cout << s.longestPalindrome("aaaaabc") << std::endl;
    std::cout << s.longestPalindrome("dvadf") << std::endl;
    std::cout << s.longestPalindrome("nfpdmpi") << std::endl;
    std::cout << s.longestPalindrome("aabaab!bb") << std::endl;
    std::cout << s.longestPalindrome("babad") << std::endl;
    return 0;
}
