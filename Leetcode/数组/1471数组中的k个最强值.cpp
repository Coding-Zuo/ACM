//
// Created by 左玉晖 on 2020/11/21.
//

//
// Created by 左玉晖 on 2020/11/20.
//  Copyright © 2020 左玉晖. All rights reserved.
// https://leetcode-cn.com/problems/remove-element/
#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getStrongest(vector<int> &arr, int k) {
        if (arr.size() == 1 || arr.size() == k)
            return arr;
        sort(arr.begin(), arr.end());
        int mIndex = ((arr.size() - 1) / 2);
        int m = arr[mIndex];
        int i = 0;
        int j = arr.size() - 1;

//        sort(arr.begin(), arr.end(), comp(m));
        vector<int> res;
        int count = 0;
        while (i <= j) {
            int maxer = 0;
            if (comp(arr[i], arr[j], m)) {
                maxer = arr[i];
                i++;
            } else {
                maxer = arr[j];
                j--;
            }
            res.push_back(maxer);
            count++;
            if (count == k) {
                break;
            }
        }
        return res;
    }

    bool comp(int a, int b, int m) {
        if (abs(a - m) > abs(b - m)) {
            return true;
        } else if ((abs(a - m) < abs(b - m))) {
            return false;
        } else {
            if (a > b) return true;
            else return false;
        }
//        return false;
    }

};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[7] = {-493, 598, -262, -918, -76, -532, 521};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    vector<int> res = sl.getStrongest(nums, 7);
    cout << 1;
    return 0;
}

