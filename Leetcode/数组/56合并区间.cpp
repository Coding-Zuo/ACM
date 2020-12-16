//
// Created by 左玉晖 on 2020/11/21.
//https://leetcode-cn.com/problems/merge-intervals/
//https://mp.weixin.qq.com/s/ioUlNa4ZToCrun3qb4y4Ow
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            int t = intervals.[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t) {
                t = max(t, intervals[j][1]);
                j++;
            }
            ans.push_back({intervals[i][0], t});
            i = j;
        }
        return ans;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[4] = {2, 7, 11, 15};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    vector<int> res = sl.twoSum(nums, 9);
    cout << 1;
    return 0;
}
