//
// Created by 左玉晖 on 2020/11/21.
//https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();
        int res = -1, right = 0;
        unordered_set<char> store;

        for (int left = 0; left < s.length(); ++left) {
            while (right < s.length() && !store.count(s[right])) {
                store.insert(s[right]);
                ++right;
            }

            res = max(res, right - left);
            store.erase(s[left]);
            if (right >= s.length()) {
                break;
            }
        }
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int res = sl.lengthOfLongestSubstring("abcabcbb");
    cout << 1;
    return 0;
}
