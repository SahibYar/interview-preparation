//
// https://leetcode.com/problems/two-sum/.
//

#include <map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::vector<int> v_return_index;
        std::map<int, int> map_index;
        int index = 0;
        // maping of values with its respective indexes
        for (const auto &n : nums) {
            map_index[n] = index;
            ++index;
        }

        index = 0;
        for (std::vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++, index++) {
            int complement = target - *iter;
            if (map_index.find(complement) != map_index.end()) {
                //value found
                std::map<int, int>::iterator second_index = map_index.find(complement);
                if (index != second_index->second) {
                    v_return_index.push_back(index);
                    v_return_index.push_back(second_index->second);
                    return v_return_index;
                }
            }
        }
        return v_return_index;
    }
};
