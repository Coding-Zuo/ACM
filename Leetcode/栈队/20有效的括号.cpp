//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/valid-parentheses/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <queue>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> stackStr;
        for (char c:s) {
            if (c == '(' || c == '{' || c == '[') {
                stackStr.push(c);
            } else {
                if (stackStr.empty()) {
                    return false;
                }
                char cs = stackStr.top();
                if (c == ']' && cs == '[') stackStr.pop();
                else if (c == '}' && cs == '{') stackStr.pop();
                else if (c == ')' && cs == '(') stackStr.pop();
                else return false;
            }
        }
        if (!stackStr.empty()) return false;
        return true;
    }

    bool isValid1(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop();
        }
        return st.empty();
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> arr1 = {2, 3};
    vector<int> arr2 = {3, 7};
    vector<int> arr3 = {4, 3};
    vector<int> arr4 = {3, 7};
    sl.isValid("{}");
    return 0;
}
