//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/number-of-rectangles-that-can-form-the-largest-square/
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
    int min(vector<int> a) { //求向量最小值
        int mindata = a[0];
        int len = a.size(), i;
        for (i = 1; i < len; i++) {
            if (a[i] < mindata)
                mindata = a[i];
        }
        return mindata;
    }

    int countGoodRectangles(vector<vector<int>> &rectangles) {
        unordered_map<int, int> map;
        for (vector<int> v:rectangles) {
            int key = min(v);
            map[key]++;
        }
        int resVal = 0;
        int reskey = 0;
        for (pair<int, int> p:map) {
            if (p.second > resVal) {
                reskey = p.first;
                resVal = p.second;
            }
        }
        return map[reskey];
    }

    int countGoodRectangles1(vector<vector<int>> &rectangles) {
        int max_len = 0, cnt = 0;
        for (int i = 0; i < rectangles.size(); i++) {
            int minlr = ::min(rectangles[i][0], rectangles[i][1]);
            if (minlr == max_len)
                cnt++;
            else if (minlr > max_len) {
                cnt = 1;
                max_len = minlr;
            }
        }
        return cnt;

    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> arr1 = {2, 3};
    vector<int> arr2 = {3, 7};
    vector<int> arr3 = {4, 3};
    vector<int> arr4 = {3, 7};
    vector<vector<int>> sandwiches = {arr1, arr2, arr3, arr4};
    sl.countGoodRectangles(sandwiches);
    return 0;
}
