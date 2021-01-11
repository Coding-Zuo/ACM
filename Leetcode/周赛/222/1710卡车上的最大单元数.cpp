//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/maximum-units-on-a-truck/
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
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
        int res = 0;
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &L, const vector<int> &R) { return L[1] > R[1]; });

        int n = 0;
        for (int i = 0; i < boxTypes.size() && truckSize > 0; i++) {
            n = min(truckSize, boxTypes[i][0]);
            truckSize -= n;
            res += n * boxTypes[i][1];
        }
        return res;

    }

    bool comp(vector<int> box1, vector<int> box2) {
        return box1[1] > box2[1];
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> arr1 = {1, 3};
    vector<int> arr2 = {2, 2};
    vector<int> arr3 = {3, 1};
    vector<vector<int>> sandwiches = {arr1, arr2, arr3};
    cout << sl.maximumUnits(sandwiches, 4);
    return 0;
}
