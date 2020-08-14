//
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
//

#include <string>
#include <deque>
#include <algorithm>

class Solution {
public:
    // I have used sliding window algorithm here.
    int lengthOfLongestSubstring(std::string s) {
        int max_length = 0;
        size_t i = 0;
        size_t j = 0;

        std::deque<char> substring;
        int difference = 0;
        for (; i < s.length();) {
            char c = s[i];
            if (std::find(substring.begin(), substring.end(), c) == substring.end()) {
                substring.push_back(c);
                difference = i - j + 1; // added +1 because index starts at 0
                ++i;
            } else {
                substring.pop_front();
                ++j;
            }
            max_length = std::max(difference, max_length);
        }
        return max_length;
    }
};

#include <iostream>
int main() {
    Solution s;
    std::cout << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << s.lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << s.lengthOfLongestSubstring("pwwkew") << std::endl;
    std::cout << s.lengthOfLongestSubstring(" ") << std::endl;
    std::cout << s.lengthOfLongestSubstring("ab") << std::endl;
    std::cout << s.lengthOfLongestSubstring("aaaaabc") << std::endl;
    std::cout << s.lengthOfLongestSubstring("dvadf") << std::endl;
    std::cout << s.lengthOfLongestSubstring("nfpdmpi") << std::endl;
    std::cout << s.lengthOfLongestSubstring("aabaab!bb") << std::endl;

    return 0;
}
