//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/design-twitter/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <set>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> hashtable;
        for (int i = 0;; i++) {
            int newx = (int) pow(x, i);
            if (newx >= bound) break;
            for (int j = 0;; j++) {
                int newy = (int) pow(y, j);
                if (newx + newy > bound) break;
                hashtable.insert(newx + newy);
                if (y == 1)break;
            }
            if (x == 1)break;
        }
        return vector<int>(hashtable.begin(), hashtable.end());
    }
};

int main(int argc, const char *argv[]) {
    cout << 1;
    return 0;
}
