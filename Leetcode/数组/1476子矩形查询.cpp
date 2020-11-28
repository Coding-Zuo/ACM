//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/subrectangle-queries/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

class SubrectangleQueries {
public:
    vector<vector<int>> rec;

    SubrectangleQueries(vector<vector<int>> &rectangle) {
        rec = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; ++i)
            for (int j = col1; j <= col2; ++j)
                rec[i][j] = newValue;
    }

    int getValue(int row, int col) {
        return rec[row][col];
    }

};

int main(int argc, const char *argv[]) {
    return 0;
}
/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */