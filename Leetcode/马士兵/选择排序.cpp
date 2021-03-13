//
// Created by 左玉晖 on 2020/11/21.
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <iomanip>

using namespace std;

#define INT_MAX 0x7fffffff

class Solution {
public:

    void selectionSort() {
        vector<int> arr = {5, 3, 6, 8, 1, 7, 9, 4, 2};
        for (int i = 0; i < arr.size() - 1; i++) {
            int minPos = i;
            int maxPos = arr.size() - i - 1;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] < arr[minPos]) minPos = j;
                if (arr[j] > arr[maxPos]) maxPos = j;
            }

            swap(arr[i], arr[minPos]);
            swap(arr[arr.size() - i - 1], arr[maxPos]);
        }

        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
    }

};


int main(int argc, const char *argv[]) {
    Solution sl;
    int a[3] = {1, 3, 1};
    int b[3] = {1, 5, 1};
    int c[3] = {4, 2, 1};
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    vector<int> nums1(b, b + sizeof(b) / sizeof(int));
    vector<int> nums2(c, c + sizeof(c) / sizeof(int));
    vector<vector<int>> grid;
    grid.push_back(nums);
    grid.push_back(nums1);
    grid.push_back(nums2);

    sl.selectionSort();
    return 0;
}
