//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/unique-paths-ii/
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
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n && obstacleGrid[0][i] == 0; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
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
