//
// Created by 左玉晖 on 2020/11/22.
// https://leetcode-cn.com/problems/n-queens/
//不能同行
//不能同列
//不能同斜线

#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;

    // n 为输入的棋盘大小
    // row 是当前递归到棋牌的第几行了
    void backtracking(int n, int row, vector<string> &chessboard) {
        if (row == n) {
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, chessboard, n)) { // 验证合法就可以放
                chessboard[row][col] = 'Q'; // 放置皇后
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.'; // 回溯，撤销皇后
            }
        }
    }

    bool isValid(int row, int col, vector<string> &chessboard, int n) {
        int count = 0;
        // 检查列
        for (int i = 0; i < row; i++) { // 这是一个剪枝
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }
        // 检查 45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查 135度角是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<string> chessboard(n, std::string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};

int main(int argc, const char *argv[]) {
//    [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
    Solution sl;
    string a[2] = {"MUC", "LHR"};
    vector<string> a1(a, a + sizeof(a) / sizeof(string));
    string b[2] = {"JFK", "MUC"};
    vector<string> b1(b, b + sizeof(b) / sizeof(string));
    string c[2] = {"SFO", "SJC"};
    vector<string> c1(c, c + sizeof(c) / sizeof(string));
    string d[2] = {"LHR", "SFO"};
    vector<string> d1(d, d + sizeof(d) / sizeof(string));

    vector<vector<string>> in({a1, b1, c1, d1});

    vector<string> res = sl.findItinerary(in);
    cout << 1;
    return 0;
}
