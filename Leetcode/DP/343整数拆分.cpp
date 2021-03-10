//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/integer-break/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <iomanip>

using namespace std;

/**
 * 确定dp数组以及下标含义
 * 拆分数字i 可以得到的最大乘积为dp[i]
 *
 * 确定递推公式
 * dp[i] = max(dp[i],max((i-j)*j, dp[i-j]*j))
 *
 * dp初始条件
 * 这里我只初始化dp[2] = 1，从dp[i]的定义来说，拆分数字2，得到的最大乘积是1，这个没有任何异议！
 *
 * 计算顺序
 * 顺序
 *
 * 举例推导dp数组
 *
 *
 * 答案是
 *
 */
#define INT_MAX 0x7fffffff

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i - 1; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    int a[3] = {1, 3, 1};
    int b[3] = {1, 5, 1};
    int c[3] = {4, 2, 1};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    vector<int> nums1(b, b + sizeof(b) / sizeof(int));
    vector<int> nums2(c, c + sizeof(c) / sizeof(int));
    vector<vector<int>> grid;
    grid.push_back(nums);
    grid.push_back(nums1);
    grid.push_back(nums2);

    return 0;
}
