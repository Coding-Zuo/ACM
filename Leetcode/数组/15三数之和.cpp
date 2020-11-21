//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/3sum/

#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出 a+b+c=0
        // a = nums[i],b=nums[left],c=nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于0，那么不可能凑成
            if (nums[i] > 0) {
                return result;
            }
            // 去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }

            }
        }
        return result;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[6] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    vector<vector<int>> res = sl.threeSum(nums);
    cout << 1;
    return 0;
}


