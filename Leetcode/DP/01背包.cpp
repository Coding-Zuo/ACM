//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/unique-paths/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <iomanip>

using namespace std;

#define INT_MAX 0x7fffffff

class Solution {
public:
    int beibao() {
        vector<int> weight = {0, 2, 3, 4, 5, 9};
        vector<int> value = {0, 3, 4, 5, 8, 10};
        int bagWeight = 20;
        vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));

        int k, w;
        for (k = 1; k < weight.size(); ++k) {
            for (w = 1; w < bagWeight + 1; ++w) {
                if (weight[k] > w) {
                    dp[k][w] = dp[k - 1][w];
                } else {
                    int value1 = dp[k - 1][w - weight[k]] + value[k];
                    int value2 = dp[k - 1][w];
                    dp[k][w] = max(value1, value2);
                }
            }
        }
        return dp[weight.size() - 1][bagWeight];

    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    int a[3] = {1, 3, 1};
    int b[3] = {1, 5, 1};
    int c[3] = {4, 2, 1};
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    vector<int> nums1(b, b + sizeof(b) / sizeof(int));
    vector<int> nums2(c, c + sizeof(c) / sizeof(int));
    vector<vector<int>> grid;
    grid.push_back(nums);
    grid.push_back(nums1);
    grid.push_back(nums2);
    cout << sl.beibao();
    return 0;
}
