//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/determine-if-string-halves-are-alike/
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
    bool halvesAreAlike(string s) {
        vector<char> yuanyin = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int countleft = 0;
        int countright = 0;
        string left = s.substr(0, s.length() / 2);
        string right = s.substr(s.length() / 2, s.length() - 1);

        for (int i = 0; i < s.length() / 2; i++) {
            for (char s :yuanyin) {
                if (left[i] == s) countleft++;
                if (right[i] == s) countright++;
            }
        }

        return (countleft == countright) ? true : false;
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    bool res = sl.halvesAreAlike("booksa");
    cout << res;
    return 0;
}
