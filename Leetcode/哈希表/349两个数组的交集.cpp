//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/valid-anagram/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num:nums2) {
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
//    bool res = sl.isAnagram("nums", "sds");
    cout << 1;
    return 0;
}
