//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/unique-paths/
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
 * 每个网格到这个网格的路径数
 *
 * 确定递推公式
 * res = dp[i-1][j]+dp[i][j-1]
 *
 * dp初始条件
 * dp[0][0]=1
 * dp[1][0]=1
 * dp[0][1]=1
 * dp[1][1]=2
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
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePaths1(int m, int n) {
        vector<int> dp(n);
        for (int i = 0; i < n; i++) dp[i] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }

    int uniquePaths2(int m, int n) {
        int numerator = 1, denominator = 1;
        int count = m - 1;
        int t = m + n - 2;
        while (count--) numerator *= (t--); // 计算分子，此时分子就会溢出
        for (int i = 1; i <= m - 1; i++) denominator *= i; // 计算分母
        return numerator / denominator;
    }

    int uniquePaths3(int m, int n) {
        long long numerator = 1; // 分子
        int denominator = m - 1; // 分母
        int count = m - 1;
        int t = m + n - 2;
        while (count--) {
            numerator *= (t--);
            while (denominator != 0 && numerator % denominator == 0) {
                numerator /= denominator;
                denominator--;
            }
        }
        return numerator;
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
