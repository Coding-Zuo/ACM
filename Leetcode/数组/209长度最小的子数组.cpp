//
// Created by 左玉晖 on 2020/11/24.
// https://leetcode-cn.com/problems/minimum-size-subarray-sum/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int result = INT32_MAX;
        int subLength = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int sum = 0;
            for (int k = i; k < nums.size(); k++) {
                sum += nums[k];
                subLength++;
                if (sum >= s) {
                    subLength = k - i + 1;
                    result = result < subLength ? result : subLength;
                    break;
                }
            }
        }
        return result == INT32_MAX ? 0 : result;
    }

    /*
     *
        窗口内是什么？ 窗口就是 满足其和 ≥ s 的长度最小的 连续 子数组。
        如何移动窗口的起始位置？ 窗口的起始位置如何移动：如果当前窗口的值大于s了，窗口就要向前移动了（也就是该缩小了）。
        如何移动窗口的结束位置？ 窗口的结束位置如何移动：窗口的结束位置就是遍历数组的指针，窗口的起始位置设置为数组的起始位置就可以了。
     */
    int minSubArrayLen1(int s, vector<int> &nums) {
        int result = INT32_MAX;
        int subLength = 0;
        int i = 0;//滑动窗口起始位置
        int sum = 0; // 滑动窗口数值之和
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[6] = {2, 3, 1, 2, 4, 3};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    int res = sl.minSubArrayLen1(7, nums);
    cout << res;
    return 0;
}
