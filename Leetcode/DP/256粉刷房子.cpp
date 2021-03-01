//
// Created by 左玉晖 on 2020/11/21.
// https://www.lintcode.com/problem/669/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <iomanip>

using namespace std;

/*
 * 确定状态
 * 最后一步：最优策略中房子N-1一定染成了 红、蓝、绿中的一种
 * 但是相邻两栋房子不能染成一种颜色
 * 所以如果最优策略中房子N-1是红色，房子N-2只能是蓝色或绿色
 * 如果根据套路，记录钱N栋房子的最小花费
 * 也要记录油漆前N-1栋房子的最小花费
 * 但前N01栋房子最小花费的最优策略中，不知道N-2是什么颜色有可能会和N-1撞色
 * 要记录颜色和钱
 *
 * 子问题
 * 求油漆前N栋房子且房子N-1是红色、蓝色、绿色的最小花费
 * 需要知道油漆前N-1栋房子并且房子N-2是红、蓝、绿的最小花费
 * 状态：设油漆前i栋房子并且房子i-1是红蓝绿的最小花费分别为
 * f[i][0] f[i][1] f[i][2]
 *
 * 转移方程
 * f[i][0] = min{f[i-1][1]+cost[i-1][0], f[i-1][2]+cost[i-1][0]}
 *
 * 初始条件和边界情况
 * 初始条件 f[0][0]=f[0][1]=f[0][2]=0 不油漆任何房子的花费
 * 无边界情况
 *
 * 计算顺序
 * f[0][0] f[0][1] f[0][2]
 * f[N][0]
 *
 * 答案是 min{f[N][0],f[N][1],f[N][2]} 时空O（N）
 */
class Solution {
public:
    int minCost(vector<vector<int>> costs) {
        int n = costs.size();
        if (n == 0) {
            return 0
        }
        int f[n + 1][3]; // f[0]...f[n]
        int res;
        f[0][0] = f[0][1] = f[0][2] = 0;
        for (int i = 0; i <= n; ++i) {
            // j是i-1栋房子的color
            for (int j = 0; j < 3; ++j) {
                f[i][j] = INTMAX_MAX;
                // k是i-2栋房子的color
                for (int k = 0; k < 3; ++k) {
                    if (j == k) {
                        continue;
                    }
                    if (f[i - 1][k] + costs[i - 1][j] < f[i][j]) {
                        f[i][j] = f[i - 1][k] + costs[i - 1][j];
                    }
                }
            }
        }

        res = f[n][0];
        if (f[n][1] < res) {
            res = f[n][1];
        }
        if (f[n][2] < res) {
            res = f[n][2];
        }
        return res;
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    return 0;
}
