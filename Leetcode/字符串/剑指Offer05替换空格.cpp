//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0, len = s.size();
        for (char c:s) {
            if (c == ' ') count++;
        }
        // 修改s长度
        s.resize(len + 2 * count);
        //倒序遍历修改
        for (int i = len - 1, j = s.size() - 1; i < j; i--, j--) {
            if (s[i] != ' ') {
                s[j] = s[i];
            } else {
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }
        return s;
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    return 0;
}
