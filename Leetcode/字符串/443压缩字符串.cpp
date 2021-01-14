//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/string-compression/
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
    int compress(vector<char> &chars) {
        int curr = 0, res = 0;
        for (int start = 0, end = 0; start < chars.size(); start = end) {
            while (end < chars.size() && chars[start] == chars[end]) {
                end++;
            }
            chars[curr++] = chars[start];
            if (end - start == 1) continue;
            for (auto c:to_string(end - start)) {
                chars[curr++] = c;
            }
        }
        return curr;
    }

    int compress1(vector<char> &chars) {
        if (chars.empty()) return 0;
        size_t j = 0;
        int cnt = 0;
        for (size_t i = 1; i <= chars.size(); i++) {
            cnt++;
            if (i == chars.size() || chars[i] != chars[j]) {
                j++;
                if (cnt != 1) {
                    for (auto c:to_string(cnt)) {
                        chars[j++] = c;
                    }
                }

                if (j == chars.size()) break;
                chars[j] = chars[i];
                cnt = 0;
            }
        }
        return j;
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    return 0;
}
