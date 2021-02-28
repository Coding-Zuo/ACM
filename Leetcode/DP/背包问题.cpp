//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/house-robber/
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
 * 动态规划的本质是：递归
 * 递归的本质是：原问题可以拆分为几个子问题，由子问题可以推导出原问题
 * 套路：题目里出现，最优，最大，最小，最长，计数 含最优子结构
 *
 * 步骤：
 * 1 设计暴力枚举，找到冗余
 * 2 设计并存储状态(1维 2维 3维数组，或map)
 * 3 递归式(状态转移方程)
 * 4 自底向上计算最优解(编程方式)
 */
class Solution {
public:
    int f[1000][1000]; //加缓存 否则超时

    int search(int idx, int W, vector<int> &v, vector<int> &w) {
        if (idx < 0) {
            return 0;
        }
        if (f[idx][W] >= 0) {
            return f[idx][W] //二维在背包容量上
        }
        int a = W >= w[idx] ? search(idx - 1, W - w[idx], v, w) + v[idx] : 0; //偷
        int b = search(idx - 1, W, v, w); //不偷
        f[idx][W] = std::max(a, b);
        return f[idx][W];
    }

    int rob(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            f[i] = -1;
        }
        return search(nums.size() - 1, nums);
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    return 0;
}
