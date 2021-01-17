//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/

#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    bool isJi(int num) {
        if (num % 2 == 1) {
            return true;
        }
        return false;
    }

    vector<int> exchange(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if ((nums[left] & 1) != 0) {
                left++;
                continue;
            }
            if ((nums[right] & 1) != 1) {
                right--;
                continue;
            }
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[3] = {1, 3, 5};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    sl.exchange(nums);
    cout << 1;
    return 0;
}


