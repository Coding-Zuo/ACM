//
// Created by 左玉晖 on 2020/11/30.
//给出一组正整数，你从第一个数向最后一个数方向跳跃，每次至少跳跃 1 格，
// 每个数的值表示你从这个位置可以跳跃的最大长度。计算如何以最少的跳跃次数跳到最后一个数。输入描述：
//
//第一行表示有多少个数 n
//
//第二行开始依次是 1 到 n 个数，一个数一行输出描述：
//
//输出一行，表示最少跳跃的次数。

#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    int jump(vector<int> arr) {
        if (arr.size() == 0) {
            return 0;
        }
        int jump = 0;//跳了多少步
        int cur = 0;//jump步内。右边界
        int next = 0;//jump+1步nei，右边界
        for (int i = 0; i < arr.size(); i++) {
            if (cur < i) {
                jump++;
                cur = next;
            }
            next = max(next, i + arr[i]);
        }
        return jump;
    }
};

int main(int argc, const char *argv[]) {
    return 0;
}
