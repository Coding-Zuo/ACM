//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/

#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int rows;
    int cols;

    bool dfs(vector<vector<char>> &borad, string word, int i, int j, int k) {

        if (i >= rows || i < 0 || j >= cols || j < 0 || borad[i][j] != word[k]) return false;
        if (k == word.size() - 1) return true;
        borad[i][j] = '\0';
        bool res = dfs(borad, word, i + 1, j, k + 1) || dfs(borad, word, i - 1, j, k + 1)
                   || dfs(borad, word, i, j + 1, k + 1) || dfs(borad, word, i, j - 1, k + 1);
        borad[i][j] = word[k];
        return res;
    }

    bool exist(vector<vector<char>> &board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[3] = {1, 3, 5};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    cout << 1;
    return 0;
}


