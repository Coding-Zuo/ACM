//
// Created by 左玉晖 on 2020/11/20.
//  Copyright © 2020 左玉晖. All rights reserved.
// https://leetcode-cn.com/problems/search-insert-position/
#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle;
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前  [0, -1]
        // 目标值等于数组中某一个元素  return middle;
        // 目标值插入数组中的位置 [left, right]，return  right + 1
        // 目标值在数组所有元素之后的情况 [left, right]， return right + 1
        return right + 1;
    }

    int baoli(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            // 分别处理如下三种情况
            // 目标值在数组所有元素之前
            // 目标值等于数组中某一个元素
            // 目标值插入数组中的位置
            if (nums[i] >= target) { // 一旦发现大于或者等于target的num[i]，那么i就是我们要的结果
                return i;
            }
        }
        // 目标值在数组所有元素之后的情况
        return nums.size(); // 如果target是最大的，或者 nums为空，则返回nums的长度
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[5] = {1, 3, 5, 6};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    int res = sl.searchInsert(nums, 5);
    cout << res;
    return 0;
}

/*
目标值在数组所有元素之前
目标值等于数组中某一个元素
目标值插入数组中的位置
目标值在数组所有元素之后

 * */
