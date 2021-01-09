//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
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
    string reverseLeftWords(string s, int n) {
        if (n >= s.length() || s.length() < 2 || n == 0) {
            return;
        }
        reverse1(s.begin(), s.begin() + n);
        reverse1(s.begin() + n, s.end());
        reverse1(s.begin(), s.end());
        return s;
    }

    void reverse1(int start, int end, string &s) {
        if (end >= s.length() || end - start < 1) {
            return;
        }
        while (start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    return 0;
}
