//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/replace-words/
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
    string replaceWords(vector<string> &dict, string sentence) {
        set<string> s;
        for (auto &a:dict)
            s.insert(a);
        stringstream ss(sentence);
        string ret;
        string init;
        if (sentence.empty())
            return ret;
        while (ss >> init) {
            for (int i = 0; i < init.size(); i++) {
                if (s.find(init.substr(0, i)) != s.end()) {
                    init = init.substr(0, i);
                }
            }
            ret = ret + init + ' ';
        }
        ret.erase(ret.end() - 1);
        return ret;
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<string> dict = {"cat", "bat", "rat"};
    sl.replaceWords(dict, "the cattle was rattled by the battery");
    cout << 1;
    return 0;
}
