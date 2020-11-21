//
// Created by 左玉晖 on 2020/11/21.
//

//
// Created by 左玉晖 on 2020/11/20.
//  Copyright © 2020 左玉晖. All rights reserved.
// https://leetcode-cn.com/problems/remove-element/
#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int baoli(vector<int> &nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--;
                size -= 1;
            }
        }
        return size;
    }

    // 双指针法（快慢指针法）：「通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。」
    int removeElement(vector<int> &nums, int val) {
        int slow = 0;
        int fast = 0;
        for (fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] == val) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[4] = {3, 2, 2, 3};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    int res = sl.removeElement(nums, 3);
    cout << res;
    return 0;
}

