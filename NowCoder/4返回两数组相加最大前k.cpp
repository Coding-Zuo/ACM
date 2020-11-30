//
// Created by 左玉晖 on 2020/11/30.
//给定两个有序数组 arr1 和 arr2, 再给定一个整数 k，返回来自 arr1 和 arr2
// 的两个数相加和最大的前 k 个，两个数必须分别来自两个数组。
//
//【举例】
//
//ar1= [1,2,3,4,5], arr2= [35,7,9,11, k=4。返回数组【16,15,14,14
//
//【要求】
//
//时间复杂度达到 0 (klogk)

#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <numeric>

using namespace std;


class TopKSUMCrossTwoArrays {
private:
    struct Node {
        int index1; //arr1中位置
        int index2;  //arr2中位置
        int sum;

        Node(int index1, int index2, int sum) : index1(index1), index2(index2), sum(sum) {}
    };

public:
    vector<int> TopKSum(vector<int> *arr1, vector<int> *arr2, int topk) {
//        topk = min(topk, arr1->size() * arr2->size());
        vector<int> result(topk);
        int resIndex = 0;

        return result;
    }

};

int main(int argc, const char *argv[]) {
    return 0;
}
