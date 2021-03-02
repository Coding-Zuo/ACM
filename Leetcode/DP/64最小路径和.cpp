//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/minimum-path-sum/
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
 * 最值型动态规划
 * 确定状态
 * 无论用何种方式达到右下角
 * 最右下角(m-1,n-1)
 * 前一步是(m-2,n-1) 或 (m-1,n-2)
 * 若倒数第二步在(m-2,n-1) 则前面一定是从(0,0)到达(m-2,n-1)总和最小的路径
 * 若倒数第二步在(m-1,n-2) 则前面一定是从(0,0)到达(m-1,n-2)总和最小的路径
 *
 * 子问题
 * 要求左上角走到(m-1,n-2)的路径最小数字总和以及走到(m-2,n-1)的最小路径总和
 *
 * 状态
 * 设从(0,0)走到(i,j)的路径最小数字总和f[i][j]
 * f[i][j] = min{f[i-1][j],f[i][j-1]} + A[i][j]
 *
 * 初始条件
 * f[0][0] = A[0][0]
 * 边界情况：i=0或j=0 前一步只能有一个方向过来
 *
 * 计算顺序
 * f[0][0]=1
 * 计算第0 到第m-1行
 *
 * 答案是
 * f[i][j] = f[i-1][j] + f[i][j-1]
 * 时间复杂度(计算步数)O(MN)
 * 空间复杂度(数组大小)O(MN)
 *
 * 空间优化
 * 计算第i行时，只需要第i行和第i-1行的f
 * 所以，只需要保存两行的f值 f[i][0...n-1] f[i-1][0...n-1]
 * 用滚动数组实现
 * 开数组时，只开f[0][0..n-1] 和f[1][0..n-1]
 * 计算f[2][0..n-1]事，删掉f[0][0...n-1]因为已经不需要f[0][0..n-1]的值了
 * 实际操作时，不用每次开数组，而是用滚动法
 * 计算f[2][0...n-1]时，把值写在f[0][0..n-1]的数组里
 * 最后f[m-1][n-1]在f[0][n-1]或者f[1][n-1]里直接输出。
 *
 *
 */
#define INT_MAX 0x7fffffff

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }

//        int f[2][n];
        vector<vector<int>> f(2, vector<int>(n, 0));
        int old = 1, now = 0;
        int t1, t2;
        for (int i = 0; i < m; ++i) {
            old = now;
            now = 1 - now;
            for (int j = 0; j < n; ++j) {
                //左上角
                if (i == 0 && j == 0) {
                    f[now][j] = grid[i][j];
                    continue;
                }

                f[now][j] = grid[i][j];
                //如果有前面一行
                if (i > 0) {
                    t1 = f[old][j];
                } else {
                    t1 = INT_MAX;
                }

                if (j > 0) {
                    t2 = f[now][j - 1];
                } else {
                    t2 = INT_MAX;
                }

                if (t1 < t2) {
                    f[now][j] += t1;
                } else {
                    f[now][j] += t2;
                }

            }
        }
        return f[now][n - 1];
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
    sl.minPathSum(grid);

    return 0;
}
