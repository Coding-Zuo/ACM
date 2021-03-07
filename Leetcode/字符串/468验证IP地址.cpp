//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/validate-ip-address/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <queue>

#include <sstream>
#include <regex>

using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        istringstream is(IP);
        string t = "";
        int cnt = 0;
        if (IP.find(':') == string::npos) { // Check IPv4 如果没有： string:npos是很大的数
            while (getline(is, t, '.')) {
                ++cnt;
                if (cnt > 4 || t.empty() || (t.size() > 1 && t[0] == '0') || t.size() > 3) return "Neither";
                for (char c : t) {
                    if (c < '0' || c > '9') return "Neither";
                }
                int val = stoi(t);
                if (val < 0 || val > 255) return "Neither";
            }
            return (cnt == 4 && IP.back() != '.') ? "IPv4" : "Neither";
        } else { // Check IPv6
            while (getline(is, t, ':')) {
                ++cnt;
                if (cnt > 8 || t.empty() || t.size() > 4) return "Neither";
                for (char c : t) {
                    if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) return "Neither";
                }
            }
            return (cnt == 8 && IP.back() != ':') ? "IPv6" : "Neither";
        }
    }

    string validIPAddress1(string IP) {
        regex ipv4(
                "(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        regex ipv6("([0-9a-fA-F]{1,4}\\:){7}[0-9a-fA-F]{1,4}");
        if (regex_match(IP, ipv4)) return "IPv4";
        else if (regex_match(IP, ipv6)) return "IPv6";
        else return "Neither";
    }

};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    sl.reverseWords("the sky is blue");
    return 0;
}
