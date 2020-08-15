//
// https://leetcode.com/problems/median-of-two-sorted-arrays/
//

#include <vector>

class Solution {
public:
    double findMedianSortedArrays(const std::vector<int> &nums1, const std::vector<int> &nums2) {
        int i = 0;
        int j = 0;

        auto iter1 = nums1.begin();
        auto iter2 = nums2.begin();

        std::vector<int> result;

        while (iter1 != nums1.end() && iter2 != nums2.end()) {
            if (nums1[i] < nums2[j]) {
                result.push_back(nums1[i]);
                ++i;
                ++iter1;
            } else if (nums2[j] < nums1[i]) {
                result.push_back(nums2[j]);
                ++j;
                ++iter2;
            } else {
                result.push_back(nums1[i]);
                result.push_back(nums2[j]);
                ++i;
                ++j;
                ++iter1;
                ++iter2;
            }
        }

        while (iter1 == nums1.end() && iter2 != nums2.end()) {
            result.push_back(nums2[j]);
            ++j;
            ++iter2;
        }

        while (iter2 == nums2.end() && iter1 != nums1.end()) {
            result.push_back(nums1[i]);
            ++i;
            ++iter1;
        }

        if ((result.size() & 1) == 1) {   // if size of result vector is odd
            return result.at((i + j) / 2);
        } else {
            size_t ceil_index = ((i + j) / 2) - 1;
            size_t floor_index = ceil_index + 1;

            double temp = result.at(ceil_index) + result.at(floor_index);
            return temp / 2;
        }
    }
};

#include <iostream>

int main() {
    Solution s;

    std::vector<int> v1 = {-1,1,2};
    std::vector<int> v2 = {0};
    std::cout << s.findMedianSortedArrays(v1, v2) << std::endl;

    std::vector<int> v3 = {1, 2};
    std::vector<int> v4 = {3, 4};
    std::cout << s.findMedianSortedArrays(v3, v4) << std::endl;

}