//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/min-cost-climbing-stairs/
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
 * 第i个台阶花费的最少体力
 *
 * 确定递推公式
 * dp[i]= min(dp[i-1],dp[i-2]) + cost[i]
 *
 * dp初始条件
 * dp[0] = cost[0]
 * dp[1] = cost[1]
 *
 * 计算顺序
 * 顺序执行
 *
 * 举例推导dp数组
 *
 *
 * 答案是
 *时间复杂度：O(n)
    空间复杂度：O(n)
 */
#define INT_MAX 0x7fffffff

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        if (cost.size() <= 1) {
            return cost[0];
        }
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); ++i) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        //最后一步可以是不用花费
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
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
