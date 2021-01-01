//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        int psize = p.length();
        vector<int> res;

        for (int k = 0; k < psize; k++) {
            map1[p[k]]++;
        }

        for (int i = 0; i < s.length(); i++) {
            map2.clear();
            int flag = 1;

            if (i + psize > s.length()) {
                break;
            }

            for (int k = i; k < i + psize; k++) {
                map2[s[k]]++;
            }
            for (int k = 0; k < psize; k++) {
                char a = map1[p[k]];
                char b = map2[p[k]];
                if (a && b) {
                    if (a != b) {
                        flag = 0;
                        break;
                    }
                } else {
                    flag = 0;
                    break;
                }
            }
            if (flag) res.push_back(i);
        }
        return res;
    }

    vector<int> findAnagrams1(string s, string p) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        int psize = p.length();
        int left = 0, right = 0;//左开右闭，len=right-left
        int valid = 0;
        vector<int> res;

        for (int k = 0; k < psize; k++) {
            map1[p[k]]++;
        }
        while (right < s.size()) {
            char c = s[right];
            right++;//右闭
            if (map1.count(c) != 0) {//map1没有直接跳过，有的话需要map2[c]++实现更新，万一更新后map2[c]==map1[c]还要valid++
                map2[c]++;
                if (map1[c] == map2[c]) valid++;
            }
            while (valid == map1.size()) {
                if (right - left == p.size()) {
                    res.push_back(left);
                }
                char d = s[left];
                left++;
                if (map1.count(d) != 0) {
                    //map1没有直接跳过，有的话主要是将map2[d]--实现更新，万一本来map2[d]==map1[d]，--之后valid就少了，left收缩结束
                    if (map2[d] == map1[d]) valid--;
                    map2[d]--;
                }
            }
        }


        return res;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> res = sl.findAnagrams("cbaebabacd", "abc");
    cout << 1;
    return 0;
}
