//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/search-a-2d-matrix/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = matrix.size();
        if (row == 0) {
            return false;
        }
        int col = matrix[0].size();
        if (col == 0) {
            return false;
        }

        for (int i = row - 1; i >= 0; i--) {
            if (matrix[i][0] == target) {
                return true;
            }
            if (matrix[i][0] < target) {
                for (int j = 0; j < col; j++) {
                    if (matrix[i][j] == target) {
                        return true;
                    }
                }
                break;
            }
        }
        return false;
    }

    bool searchMatrix1(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();

        // 二分查找
        int left = 0, right = m * n - 1;
        int pivotIdx, pivotElement;
        while (left <= right) {
            pivotIdx = (left + right) / 2;
            pivotElement = matrix[pivotIdx / n][pivotIdx % n];
            if (target == pivotElement) return true;
            else {
                if (target < pivotElement) right = pivotIdx - 1;
                else left = pivotIdx + 1;
            }
        }
        return false;
    }

};


int main(int argc, const char *argv[]) {
    Solution sl;
//    [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    int a1[4] = {1, 3, 5, 7};
    int a2[4] = {10, 11, 16, 20};
    int a3[4] = {23, 30, 34, 50};
    int a4[1] = {1};
    vector<int> row1(a1, a1 + sizeof(a1) / sizeof(int));
    vector<int> row2(a2, a2 + sizeof(a2) / sizeof(int));
    vector<int> row3(a3, a3 + sizeof(a3) / sizeof(int));
    vector<int> row4(a4, a4 + sizeof(a4) / sizeof(int));
    vector<vector<int>> mat;
    vector<vector<int>> mat1;
    mat.push_back(row1);
    mat.push_back(row2);
    mat.push_back(row3);
    mat1.push_back(row4);
    sl.searchMatrix(mat1, 3);
    cout << 1;
    return 0;
}
