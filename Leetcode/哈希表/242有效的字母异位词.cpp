//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/valid-anagram/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            //相对数值
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    bool res = sl.isAnagram("nums", "sds");
    cout << 1;
    return 0;
}
