//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
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
 * 最后一步：对于最优的策略，一定有最后一个元素a[j]
 * 第一种情况，最优策略中最长连续上升子序列就是{a[j]}，答案是1
 * 第二中情况，子序列长度大于1，那么最优策略中a[j]前一个元素肯定是a[j-1]。这种情况一定是a[j-1]<a[j]
 * 因为是最优策略，那么它选中的以a[j-1]结尾的连续上升子序列一定是最长的
 *
 * 子序列
 * 要求以a[j-1]结尾的最长连续上升子序列
 * 本来是以a[j]结尾的最长连续上升子序列
 *
 * 状态
 * 设f[j]=以a[j]结尾的最长连续上升子序列的长度
 * f[j]=max{1, f[j-1]+1 | j>0 and a[j-1] < a[j]}
 * 情况1 子序列就是a[j]本身
 * 情况2 以a[j-1]结尾的最长连续上升子序列的长度,加上a[j]
 * 情况2必须满足：
 *      j>0,即a[j]前面至少还有一个元素
 *      a[j]>a[j-1] 满足单调性
 *
 * 初始条件
 * 空
 *
 * 计算顺序
 * f[j] = 以a[j]结尾的最长连续上升子序列的长度
 * 计算f[0]...f[N]
 * 和硬币组合不同的是，最终答案不一定是f[n-1]
 * 因为不知道最优策略中最后一个元素是哪个a[j]结尾
 *
 * 答案是 max{f[0],f[1]...f[n-1]}
 * 时空O(n)
 * 增加滚动数组可优化空间复杂度为O(1)
 */
class Solution {
public:

    int result = 0;

    void calc(vector<int> &nums, int n) {
//        int f[n];
        int f[2];
        int old, now = 0; //f[i] -> now f[i=1] - >old
        for (int i = 0; i < n; ++i) {
            old = now;
            now = 1 - now;
            f[now] = 1;
            if (i > 0 && nums[i - 1] < nums[i]) {
                f[now] = f[old] + 1;
            }
            if (f[now] > result) {
                result = f[now];
            }
        }
    }

    int findLengthOfLCIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        calc(nums, n);

        // inverse A
        int i, j, t;
        i = 0;
        j = n - 1;
        while (i < j) {
            t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            ++i;
            --j;
        }

        calc(nums, n);
        return result;
    }


};


int main(int argc, const char *argv[]) {
    Solution sl;
    return 0;
}
