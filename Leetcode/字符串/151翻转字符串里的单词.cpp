//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/reverse-words-in-a-string/
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
    string reverseWords(string s) {

        vector<string> res;
        string cur = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ' ' && cur != "") {
                if (cur != "") {
                    res.push_back(cur);
                    cur = "";
                } else {
                    continue;
                }
            }
            if (s[i] != ' ') cur = s[i] + cur;
            if (i == 0 && s[i] != ' ') {
                res.push_back(cur);
            }
        }
        string ans;

        for (int i = 0; i < res.size(); i++) {
            ans += res[i];
            if (i != res.size() - 1) ans += ' ';
        }
        return ans;
    }

    //原地算法
    // 翻转字符串s中左闭右开的区间[start,end]
    void reverse(string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    //移除冗余空格，使用双指针(快慢指针法) O(n)算法
    void removeExtraSpace(string &s) {
        int slowIndex = 0, fastIndex = 0;
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for (; fastIndex < s.size(); fastIndex++) {
            //去掉字符串中冗余空格
            if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' ') {
                continue;
            } else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') {
            // 去掉字符串末尾空格
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex);
        }
    }

    string reverseWords1(string s) {
        removeExtraSpace(s);
        reverse(s, 0, s.size() - 1);//将字符串全部翻转
        int start = 0; //翻转单词在字符串里起始位置
        int end = 0; //翻转的单词在字符串终止位置
        bool entry = false; //标记枚举字符串的过程中是否进入了单词区间
        for (int i = 0; i < s.size(); i++) {
            //翻转单词
            if ((!entry) || (s[i] != ' ' && s[i - 1] == ' ')) {
                start = i;
                entry = true;
            }
            //单词后有空格情况，空格就是分词符
            if (entry && s[i] == ' ' && s[i - 1] != ' ') {
                end = i - 1; // 确定单词终止位置
                entry = false; // 结束单词区间
                reverse(s, start, end);
            }
            // 最后一个结尾单词之后没有空格的情况
            if (entry && (i == (s.size() - 1)) && s[i] != ' ') {
                end = i;// 确定单词终止位置
                entry = false; // 结束单词区间
                reverse(s, start, end);
            }
        }
        return s;
    }

};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    sl.reverseWords("the sky is blue");
    return 0;
}
