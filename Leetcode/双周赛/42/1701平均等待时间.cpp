//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/average-waiting-time/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <iomanip>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>> &customers) {
        setiosflags(ios::fixed);
        setprecision(5);
        double sum = 0;
        int cur = customers[0][0];
        for (int i = 0; i < customers.size(); i++) {
            int arrivali = customers[i][0];
            if (arrivali > cur) {
                cur = arrivali;
            }
            int timei = customers[i][1];
            int reduce = cur - arrivali;
            cur += timei;
            sum += timei;
            if (reduce > 0) sum += reduce;
        }
        sum = sum / customers.size();
        return sum;
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
//    vector<vector<int>> customers = {{5,  2},
//                                     {5,  4},
//                                     {10, 3},
//                                     {20, 1}};
    vector<vector<int>> customers = {{2,  3},
                                     {6,  3},
                                     {7,  5},
                                     {11, 3},
                                     {15, 2},
                                     {18, 1}};
    double res = sl.averageWaitingTime(customers);
//    sl.countStudents(students, sandwiches);
    cout << res;
    return 0;
}
