//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/

#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int i=0;
        int j = nums.size()-1;
        while(i<=j){
            int m = (i+j)/2;
            if(nums[m]==m) i = m+1;
            else j=m-1;
        }
        return i;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[6] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    cout << 1;
    return 0;
}


