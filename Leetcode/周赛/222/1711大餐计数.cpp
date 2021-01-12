//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/count-good-meals/
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
    int countPairs(vector<int> &deliciousness) {
        unordered_set<int> resSet{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        int preFirst = 0, preLast = deliciousness.size() - 1;
        int first = 0, last = deliciousness.size() - 1;
        int res = 0;
        while (first <= last) {
            int cur = deliciousness[first] + deliciousness[last];
            if (isPowerOf2(cur)) {
                res++;
            }
            while (deliciousness[++first] == deliciousness[preFirst]) {
                res++;
                preFirst++;
            }
            while (deliciousness[++last] == deliciousness[preLast++]) {
                res++;
                preLast++;
            }
            first++;
        }
        return res;
    }

    bool isPowerOf2(int num) {
        return (num & (num - 1)) == 0;
    }

    iint countPairs(vector<int> &d) {
        sort(d.begin(), d.end());
        const int M = 1e9 + 7;
        vector<int> vec(3000000);
        long long ans = 0;
        for (int i = 0; i < d.size(); i++) {
            ans += vec[d[i]];
            for (int j = 0; j < 22; j++) {
//                1<<i是求2^i
//                if(i&(1<<j))  ：i&(1<<j)是指i等于2^j ，所以这句话的意思是if(i==2^j)
                if (((1 << j) - d[i]) >= 0) vec[(1 << j) - d[i]]++;
            }
        }
        return ans % M;
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> arr1 = {1, 3};
    vector<int> arr2 = {2, 2};
    vector<int> arr3 = {3, 1};
    vector<vector<int>> sandwiches = {arr1, arr2, arr3};
    return 0;
}
