//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/set-matrix-zeroes/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        bool flag = false;      //用作第一列的标识位
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i)       //设置标识位
        {
            if (matrix[i][0] == 0) flag = true;    //单独判断第一列的情况
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = m - 1; i >= 0; --i)       //更新数值时，因为标识位都在左上角，所以自下而上更新0值
        {
            for (int j = n - 1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if (flag) matrix[i][0] = 0;   //第一列元素单独判断
        }
    }
};

// Brute force
class Solution1 {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }

        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<int>> copy = matrix;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (rowContainsZero(i, copy) || colContainsZero(j, copy)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

private:
    bool rowContainsZero(int i, vector<vector<int>> &copy) {
        for (int j = 0; j < copy[i].size(); j++) {
            if (copy[i][j] == 0) {
                return true;
            }
        }

        return false;
    }

    bool colContainsZero(int j, vector<vector<int>> &copy) {
        for (int i = 0; i < copy.size(); i++) {
            if (copy[i][j] == 0) {
                return true;
            }
        }

        return false;
    }
};

class Solution2 {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }

        int M = matrix.size();
        int N = matrix[0].size();
        vector<bool> rowNeedToSet(M, false);
        vector<bool> colNeedToSet(N, false);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 0) {
                    rowNeedToSet[i] = true;
                    colNeedToSet[j] = true;
                }
            }
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (rowNeedToSet[i] || colNeedToSet[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Smartest algorithm, use first row and first col as the space used in Solution 2.
class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }

        int M = matrix.size();
        int N = matrix[0].size();

        bool needSetFirstCol = false;
        for (int i = 0; i < M; i++) {
            if (matrix[i][0] == 0) {
                needSetFirstCol = true;
                break;
            }
        }

        bool needSetFirstRow = false;
        for (int j = 0; j < N; j++) {
            if (matrix[0][j] == 0) {
                needSetFirstRow = true;
                break;
            }
        }

        // Mark rest or not state to first row and first col
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (needSetFirstCol) {
            for (int i = 0; i < M; i++) {
                matrix[i][0] = 0;
            }
        }

        if (needSetFirstRow) {
            for (int j = 0; j < N; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
//    [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    int a1[4] = {0, 1, 2, 0};
    int a2[4] = {3, 4, 5, 2};
    int a3[4] = {1, 3, 1, 5};
    vector<int> row1(a1, a1 + sizeof(a1) / sizeof(int));
    vector<int> row2(a2, a2 + sizeof(a2) / sizeof(int));
    vector<int> row3(a3, a3 + sizeof(a3) / sizeof(int));
    vector<vector<int>> mat;
    mat.push_back(row1);
    mat.push_back(row2);
    mat.push_back(row3);
    sl.setZeroes(mat);
    cout << 1;
    return 0;
}
