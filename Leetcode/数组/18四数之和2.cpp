//
// Created by 左玉晖 on 2020/11/22.
// https://leetcode-cn.com/problems/4sum-ii/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        int count = 0;
        unordered_map<int, int> umap;//key:a+b的数值，value:a+b数值出现的次数
        // 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中
        for (int a :A) {
            for (int b:B) {
                umap[a + b]++;
            }
        }
        // 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来。
        for (int c : C) {
            for (int d : D) {
                if (umap.find(0 - (c + d)) != umap.end()) {
                    count += umap[0 - (c + d)];
                }
            }
        }

        return count;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[2] = {1, 2};
    int b[2] = {-2, -1};
    int c[2] = {-1, 2};
    int d[2] = {0, 2};
    vector<int> a1(a, a + sizeof(a) / sizeof(int));
    vector<int> b1(b, b + sizeof(b) / sizeof(int));
    vector<int> c1(c, c + sizeof(c) / sizeof(int));
    vector<int> d1(d, d + sizeof(d) / sizeof(int));
    int count = sl.fourSumCount(a1, b1, c1, d1);
    cout << count;
    return 0;
}

