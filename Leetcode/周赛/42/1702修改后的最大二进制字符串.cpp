//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/maximum-binary-string-after-change/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>

using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int sz = 0, f;
        for (int i = 0; i < binary.size(); i++) {
            if (sz == 0 && binary[i] == '0') {
                sz++;
                f = i;
            } else if (binary[i] == '0') {
                sz++;
            }
            binary[i] = '1';
        }
        if (sz > 1) {
            binary[f + sz - 1] = '0';
            return binary;
        } else if (sz == 1) {
            binary[f] = '0';
        } else if (sz == 0) {
            return binary;
        }
        return binary;
    }

    string maximumBinaryString1(string binary) {
        int len = binary.size();
        string s = binary;
        int cnt1 = 0, cnt2 = 0;
        int pos = -1;
        for (int i = 0; i < len; i++) {
            if (s[i] == '0') {
                pos = i - 1;
                break;
            }
        }
        for (int i = pos + 1; i < len; i++) {
            if (s[i] == '0') {
                cnt1++;
            } else {
                cnt2++;
            }
        }
        string t = "";
        for (int i = 0; i <= pos; i++) t += '1';
        for (int i = 0; i < cnt1; i++) t += '0';
        for (int i = 0; i < cnt2; i++) t += '1';
        for (int i = 0; i < t.size() - 1; i++) {
            if (t[i] == '0' && t[i + 1] == '0') {
                t[i] = '1';
            }
        }
        return t;
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    cout << 1;
    return 0;
}
