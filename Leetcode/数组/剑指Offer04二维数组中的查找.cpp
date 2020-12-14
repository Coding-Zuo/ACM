//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/

#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        int i = matrix.size() - 1;
        int j = 0;
        while (i >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] > target) i--;
            else if (matrix[i][j] < target) j++;
            else return true;
        }
        return false;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[6] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    cout << 1;
    return 0;
}


