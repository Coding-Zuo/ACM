//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/tuple-with-same-product/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <queue>

using namespace std;


class Solution {
public:
    int tupleSameProduct(vector<int> &nums) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int cnt = it->second;
            ans += (cnt) * (cnt - 1) / 2 * 8;
        }
        return ans;
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> arr1 = {2, 3};
    vector<int> arr2 = {3, 7};
    vector<int> arr3 = {4, 3};
    vector<int> arr4 = {3, 7};
    vector<vector<int>> sandwiches = {arr1, arr2, arr3, arr4};
    return 0;
}
