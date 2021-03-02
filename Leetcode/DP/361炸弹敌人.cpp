//
// Created by 左玉晖 on 2020/11/21.
// https://www.cnblogs.com/grandyang/p/5599289.html
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
 * 确定状态
 * 假设有敌人或有墙的格子也能放炸弹
 * - 有敌人的格子：格子里的敌人被炸死，并且继续向上爆炸
 * - 有墙的格子：炸弹不能炸死任何敌人
 * 在(i,j)格子放一个炸弹，它能向上炸死的敌人数是：
 * - (i,j)为空地：(i-1,j)格向上能炸死的敌人数
 * - (i,j)为敌人：(i-1,j)格能炸死的敌人数+1
 * - (i,j)格为墙：0
 *
 * 子问题
 * 需要知道(i-1,j)格放一个炸弹向上能炸死的敌人数
 * 原来要求(i,j)格放一个炸弹向上能炸死的敌人数
 *
 * 状态
 * - Up[i][j]表示(i,j)格放一个炸弹向上能炸死的敌人数
 *  Up[i][j] = 如果(i,j)是空地 Up[i-1][j]
 *              如果(i,j)是敌人 Up[i-1][j]+1
 *              如果是墙 0
 *
 * 初始条件
 * 第0行的Up值和格子内容相关
 * - Up[0][j]=0 如果(0,j)格不是敌人
 * - Up[0][j]=1 如果(0,j)是敌人
 *
 * 计算顺序
 * 逐行计算
 *
 * 答案是
 * 一共计算四个方向 Up Down Left Right
 * (i,j)如果是空地，最多炸死
 * - Up[i][j] + Down[i][j] + Left[i][j] + Right[i][j]
 * 取最大值即可
 *
 * 时空O(Mn)
 * 空间优化
 *
 *
 */
#define INT_MAX 0x7fffffff

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>> &grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }

        int f[m][n];
        int res[m][n]; //有多少个敌人可以被一次杀死
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = 0;
            }
        }
        //up
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'W') {
                    f[i][j] = 0;
                } else {
                    f[i][j] = 0;
                    if (grid[i][j] == 'E') {
                        f[i][j] = 1;
                    }
                    if (i - 1 >= 0) { //如果有上一行
                        f[i][j] += f[i - 1][j];
                    }
                }

                res[i][j] += f[i][j];
            }
        }
        //down
        for (int i = m - 1; i >= 0; --i) { //倒过来算
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'W') {
                    f[i][j] = 0;
                } else {
                    f[i][j] = 0;
                    if (grid[i][j] == 'E') {
                        f[i][j] = 1;
                    }
                    if (i + 1 < m) { //如果有下一行
                        f[i][j] += f[i + 1][j];
                    }
                }

                res[i][j] += f[i][j];
            }
        }
        //left
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'W') {
                    f[i][j] = 0;
                } else {
                    f[i][j] = 0;
                    if (grid[i][j] == 'E') {
                        f[i][j] = 1;
                    }
                    if (j - 1 >= 0) { //如果有左一列
                        f[i][j] += f[i][j - 1];
                    }
                }

                res[i][j] += f[i][j];
            }
        }
        //right
        for (int i = 0; i < m; ++i) {
            for (int j = n - 1; j >= 0; --j) {//倒过来算
                if (grid[i][j] == 'W') {
                    f[i][j] = 0;
                } else {
                    f[i][j] = 0;
                    if (grid[i][j] == 'E') {
                        f[i][j] = 1;
                    }
                    if (j + 1 < n) { //如果有左一列
                        f[i][j] += f[i][j + 1];
                    }
                }

                res[i][j] += f[i][j];
            }
        }

        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    if (res[i][j] > result) {
                        result = res[i][j];
                    }
                }
            }
        }


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
