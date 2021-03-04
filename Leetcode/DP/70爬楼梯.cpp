//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/fibonacci-number/
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
 * 没个阶数有多少种方法爬
 *
 * 确定递推公式
 * dp[i]= dp[i-1] + dp[i-2]
 *
 * dp初始条件
 * dp[1]=1 dp[2]=2
 *
 * 计算顺序
 * 从前向后
 *
 * 举例推导dp数组
 *  n=5
 *  1 2 3 5 8
 *
 * 答案是
 *
 */
#define INT_MAX 0x7fffffff

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return n;
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
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
