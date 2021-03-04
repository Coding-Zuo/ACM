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
 * dp[i]是第i个数的斐波那契值是dp[i]
 *
 * 确定递推公式
 * F(n) = F(n-1) + F(n-2)
 *
 * dp初始条件
 * F(1)= 1 F(2)=1
 *
 * 计算顺序
 * 从前向后
 *
 * 举例推导dp数组
 *  当N为10
 *  0 1 1 2 3 5 8 13 21 34 55
 *
 * 答案是
 * 时空On
 * 可加滚动数组
 *
 */
#define INT_MAX 0x7fffffff

class Solution {
public:
    int fib(int N) {
        if (N <= 1) return N;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
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
