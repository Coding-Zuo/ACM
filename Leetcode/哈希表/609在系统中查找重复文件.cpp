//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/find-duplicate-file-in-system/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void split(const std::string &s, std::vector<std::string> &elems, char delim = ' ') {
        std::stringstream ss;
        ss.str(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }

//    string cur = s[i];
//    cur = cur.substr(cur.find("(")+1 ,cur.find(")")-cur.find("(")-1);

    vector<vector<string>> findDuplicate(vector<string> &paths) {
        //key为文件内容，value为目录+文件名
        unordered_map<string, vector<string>> m;
        for (string s:paths) {
            //' '前的字符串即为目录，为其追加一个'/'
            int start = s.find(' ');
            string path = s.substr(0, start).append(1, '/');
            //寻找(
            int leftBracket = s.find('(', start);
            while (leftBracket != -1) {
                //根据'('和' '的位置确定文件名
                string fileName = s.substr(start + 1, leftBracket - start - 1);
                //寻找`)`
                int rightBracket = s.find(')', leftBracket);
                //根据'('和')'的位置确定文件内容，将其作为key，目录和文件名作为value
                m[s.substr(leftBracket + 1, rightBracket - leftBracket - 1)].emplace_back(path + fileName);
                //继续寻找该目录的下一个文件
                start = rightBracket + 1;
                leftBracket = s.find('(', start);
            }
        }
        //找出具有重复内容的文件路径
        vector<vector<string>> result;
        for (auto &p : m) {
            if (p.second.size() >= 2) {
                result.emplace_back(p.second);
            }
        }
        return result;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> res = sl.findAnagrams("cbaebabacd", "abc");
    cout << 1;
    return 0;
}
