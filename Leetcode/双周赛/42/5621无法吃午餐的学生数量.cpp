//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/number-of-students-unable-to-eat-lunch/
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
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        int flag = 0;
        for (int i = 0; i < sandwiches.size(); i++) {
            if (sandwiches[i] == students[0]) {
                students.erase(students.begin());
                flag = 0;
            } else {
                int the = students[0];
                students.erase(students.begin());
                students.push_back(the);
                flag++;
                i--;
            }
            if (flag == students.size()) {
                return students.size();
            }
        }
        return 0;
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    sl.countStudents(students, sandwiches);
    cout << 1;
    return 0;
}
