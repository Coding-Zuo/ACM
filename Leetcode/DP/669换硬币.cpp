//
// Created by 左玉晖 on 2020/11/21.
// https://www.lintcode.com/problem/669/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <iomanip>

using namespace std;

class Solution {
public:
    int f[1000]; //加缓存 否则超时

    int search(int X) {
        if (idx < 0) {
            return 0;
        }
        int res = INTMAX_MAX;
        if (X >= 2) {
            res = std::min(search(X - 2) + 1, res);
        }
        if (X >= 5) {
            res = std::min(search(X - 5) + 1, res);
        }
        if (X >= 7) {
            res = std::min(search(X - 7) + 1, res);
        }
        return res;
    }

    int coinChange(vector<int> &A, int M) {
        int n = A.size();
        int f[M + 1];
        f[0] = 0;
        for (int i = 1; i <= M; ++i) {
            f[i] = INTMAX_MAX;
            for (int j = 0; j < n; ++j) {
                if (i >= A[j] && f[i - A[j]] != INTMAX_MAX && f[i - A[j]] + 1 < f[i]) {
                    f[i] = f[i - A[j]] + 1;
                }
            }
        }
        if (f[M] == INTMAX_MAX) {
            return -1;
        } else {
            return f[M]
        }
    }

    int uniquePaths(int m, int n) {
        int f1[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    f1[i][j] = 1;
                } else {
                    f1[i][j] = f1[i - 1][j] + f1[i][j - 1];
                }
            }
        }
        return f1[m - 1][n - 1];
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    return 0;
}
