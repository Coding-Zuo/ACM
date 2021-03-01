//
// Created by 左玉晖 on 2020/11/21.
// https://www.lintcode.com/problem/115/solution
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
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if (n == 0) {
            return 0;
        }
        int f[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    f[i][j] = 0;
                } else {
                    if (i == 0 && j == 0) {
                        f[i][j] = 1;
                    } else {
                        f[i][j] = 0;
                        if (i - 1 >= 0) {
                            f[i][j] += f[i - 1][j];
                        }
                        if (j - 1 >= 0) {
                            f[i][j] += f[i][j - 1];
                        }
                    }
                }
            }
        }
        return f[m - 1][n - 1];

    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    return 0;
}
