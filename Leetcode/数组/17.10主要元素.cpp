//
// Created by 左玉晖 on 2020/11/26.
// https://leetcode-cn.com/problems/find-majority-element-lcci/

#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> hash;
        for (auto x : nums) {
            hash[x]++;
            if (hash[x] > nums.size() / 2)
                return x;
        }

        return -1;
    }

    int majorityElement1(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; (i + nums.size() / 2) < nums.size(); i++) {
            //每次步进一半的元素就可以判断num[i]是否为主要元素
            if (nums[i] == nums[i + nums.size() / 2])
                return nums[i];
        }

        return -1;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[4] = {1, 2, 2, 3};
    int b[3] = {4, 5, 6};
    int c[3] = {7, 8, 9};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    vector<int> nums1(b, b + sizeof(b) / sizeof(int));
    vector<int> nums2(c, c + sizeof(c) / sizeof(int));
    vector<vector<int>> num;
    num.push_back(nums);
    num.push_back(nums1);
    num.push_back(nums2);
    int res = sl.majorityElement(nums);
    cout << 1;
    return 0;
}

