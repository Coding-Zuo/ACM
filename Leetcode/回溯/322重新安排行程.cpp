//
// Created by 左玉晖 on 2020/11/22.
//

#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
private:
    // unordered_map<出发机场,map<到达机场，航班次数>> target
    unordered_map<string, map<string, int>> targets;

    bool backtracking(int ticketNum, vector<string> &result) {
        if (result.size() == ticketNum + 1) {
            return true;
        }
        for (pair<const string, int> &target : targets[result[result.size() - 1]]) {
            if (target.second > 0) { // 记录到达机场是否飞过了
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, result)) return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        targets.clear();
        vector<string> result;
        for (const vector<string> &vec : tickets) {
            targets[vec[0]][vec[1]]++;
        }
        result.push_back("JFK");
        backtracking(tickets.size(), result);
        return result;
    }
};

int main(int argc, const char *argv[]) {
//    [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
    Solution sl;
    string a[2] = {"MUC", "LHR"};
    vector<string> a1(a, a + sizeof(a) / sizeof(string));
    string b[2] = {"JFK", "MUC"};
    vector<string> b1(b, b + sizeof(b) / sizeof(string));
    string c[2] = {"SFO", "SJC"};
    vector<string> c1(c, c + sizeof(c) / sizeof(string));
    string d[2] = {"LHR", "SFO"};
    vector<string> d1(d, d + sizeof(d) / sizeof(string));

    vector<vector<string>> in({a1, b1, c1, d1});

    vector<string> res = sl.findItinerary(in);
    cout << 1;
    return 0;
}
