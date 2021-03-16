//
// https://leetcode-cn.com/problems/min-cost-to-connect-all-points/
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

struct Edge {
    int start; //顶点1
    int end; //顶点2
    int len; //长度
};

class Djset {
public:
    vector<int> parent; //记录根节点
    vector<int> rank; //记录根节点的深度 用于优化
    vector<int> size; //记录每个连通分量的节点个数
    vector<int> len; //记录每个连通分量里的所有边长度
    int num;  //记录节点个数

    Djset(int n) : parent(n), rank(n), len(n, 0), size(n, 1), num(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        //压缩方式：直接指向根节点
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    int merge(int x, int y, int length) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            // rooty的父节点设置为rootx，同时将rooty的节点数和边长度累加到rootx
            size[rootx] += size[rooty];
            len[rootx] += len[rooty] + length;
            // 如果某个连通分量的节点数包含了所有节点，直接返回边长度
            if (size[rootx] == num) return len[rootx];
        }
        return -1;
    }


    void init(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

};

class Solution {
public:
    int distence(vector<int> x, vector<int> y) {
        return abs(x[0] - y[0]) + abs(x[1] - y[1]);
    }

    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size();
        int res = 0;
        vector<Edge> edges;

        Djset ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                Edge edge = {i, j, distence(points[i], points[j])};
                edges.emplace_back(edge);
            }
        }

        // 按边长度排序
        sort(edges.begin(), edges.end(), [](const auto &a, const auto &b) {
            return a.len < b.len;
        });

        //连通分量合并
        for (auto &e:edges) {
            res = ds.merge(e.start, e.end, e.len);
            if (res != -1) return res;
        }
        return 0;

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

    return 0;
}
