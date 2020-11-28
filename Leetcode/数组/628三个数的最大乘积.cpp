//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/maximum-product-of-three-numbers/

#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        int qian = 2;
        int hou = 0;
        int res = nums[hou] * nums[qian] * nums[hou + 1];
        sort(nums.begin(), nums.end());

        return max(nums[0] * nums[1] * nums[nums.size() - 1],
                   nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]);
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[7] = {-7, -7, 1, 2, 3, 4, 5};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    int res = sl.maximumProduct(nums);
    cout << res;
    return 0;
}


