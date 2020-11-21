//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/two-sum/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                return {iter->second, i};
            }
            map.insert(nums[i], i);
        }
        return {};
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[4] = {2, 7, 11, 15};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    vector<int> res = sl.twoSum(nums, 9);
    cout << 1;
    return 0;
}
