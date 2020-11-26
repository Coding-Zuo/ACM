//
// Created by 左玉晖 on 2020/11/26.
// https://leetcode-cn.com/problems/transpose-matrix/

#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> &A) {
        int row = A.size();
        int col = A[0].size();

        vector<vector<int>> temp(col, vector<int>(row, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                temp[j][i] = A[i][j];
            }
        }
        return temp;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[3] = {1, 2, 3};
    int b[3] = {4, 5, 6};
    int c[3] = {7, 8, 9};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    vector<int> nums1(b, b + sizeof(b) / sizeof(int));
    vector<int> nums2(c, c + sizeof(c) / sizeof(int));
    vector<vector<int>> num;
    num.push_back(nums);
    num.push_back(nums1);
    num.push_back(nums2);
    vector<vector<int>> res = sl.transpose(num);
    cout << 1;
    return 0;
}

