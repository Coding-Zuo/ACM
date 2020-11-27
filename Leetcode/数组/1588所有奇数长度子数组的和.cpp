//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int res = 0;
        for (int i = 0; i < arr.size(); i++)
            for (int sz = 1; i + sz - 1 < arr.size(); sz += 2)
                res += accumulate(arr.begin() + i, arr.begin() + i + sz, 0);
        return res;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[5] = {1, 4, 2, 5, 3};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    int res = sl.sumOddLengthSubarrays(nums);
    cout << res;
    return 0;
}
