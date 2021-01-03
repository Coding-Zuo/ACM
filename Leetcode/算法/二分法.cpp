//
// Created by 左玉晖 on 2020/11/21.
//http://blog.csdn.net/flushhip/article/details/79052383
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
    //最普通的二分
    bool bFind(int a[], int left, int right, int tag) {
        for (; left <= right;) {
//            int mid =(left+right)>>1;
            int mid = (left + right) / 2;
            if (a[mid] == tag) {
                return true;
            } else {
                a[mid] < tag > l = mid + 1:r = mid - 1;
            }
        }
        return false;
    }

    //找上下界模板
    bool cmp1(const int &a, const int &b) {
        return a >= b;
    }

    bool cmp2(const int &a, const int &b) {
        return a <= b;
    }

    //求下界
    int getDown(vector<int> data, int k, bool (*cmp)(const int &, const int &)) {
        int l, r;
        for (l = 0, r = data.size(); l < r;) {
            int mid = (l + r) / 2;
            if (!cmp(data[mid], k)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

    //求上界
    int getUp(vector<int> data, int k) {
        int l, r;
        for (l = -1, r = data.size() - 1; l < r;) {
            int mid = (l + r + 1) / 2;
            if (!cmp(data[mid], k)) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }

    //统计一个数字在升序数组中出现的次数。
    int GetNumberOfK(vector<int> data, int k) {
        int pre, last, l, r;
        //下界
        for (l = 0, r = data.size(); l < r;) {
            int mid = (l + r) / 2;
            if (data[mid] >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        pre = r;

        //上界
        for (l = -1, r = (int) data.size() - 1; l < r;) {
            int mid = (l + r + 1) / 2;
            if (data[mid] <= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
            last = l;
            return last - pre + 1;
        }
    }


};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    cout << 1;
    return 0;
}
