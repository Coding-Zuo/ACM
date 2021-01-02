//
// Created by 左玉晖 on 2020/11/21.
//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
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
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        sort(nums.begin(), nums.end());
//        int count = 1;
//        for (int i = 0; i < nums.size(); i++) {
//            int num = nums[i];
//            if (num[i + 1] != num) {
//                continue;
//            }
//        }

        int left = 0;
        int right = 1;
        while (right + 1 < nums.size()) {
            if (nums[left] == nums[right] && nums[left] == nums[right + 1]) {
                //清除right+1

                remove(right + 1, nums);
            } else {
                left++;
                right++;
            }
        }
        return nums.size();
    }

    void remove(int index, vector<int> &nums) {
        for (int i = index; i < nums.size() - 1; i++) {
            nums[i] = nums[i + 1];
        }
        nums.pop_back();
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> students = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int size = sl.removeDuplicates(students);
    cout << size;
    return 0;
}
