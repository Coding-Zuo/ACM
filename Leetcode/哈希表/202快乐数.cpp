//
// Created by 左玉晖 on 2020/11/21.
//https://leetcode-cn.com/problems/happy-number/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    //取 数值各个位上的单数之和
    int getsum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> set;
        while (1) {
            int sum = getsum(n);
            if (sum == 1) {
                return true;
            }
            if (set.find(sum) != set.end()) {
                return false;
            } else {
                set.insert(sum);
            }
            n = sum;
        }
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
//    bool res = sl.isAnagram("nums", "sds");
    cout << 1;
    return 0;
}
