//
//https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column/
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

class Djset {
public:
    vector<int> parent; //记录节点的根
    vector<int> rank; //记录根节点的深度用于优化
    Djset(int n) : parent(vector<int>(n)), rank(vector<int>(n)) {
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

    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            //按智合并
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
        }
    }
};

class UF {
public:
    UF(int n);

    bool connected(int w, int v); // 判断是否连通
    void Union(int w, int v); // 合并两个集合,大写首字母为了区别关键字
    int find(int p);  //找到p所在集合的根

private:
    vector<int> *m_parent = nullptr; // parent[i] = parent of i
    vector<int> *m_rank = nullptr; //rank[i] = rank of subtree at i
    int m_count = 0; // number of components
    void validate(int p);
};

UF::UF(int n) {
    m_parent = new vector<int>(n);
    m_rank = new vector<int>(n, 0);

    for (int i = 0; i < n; i++) {
        m_parent->at(i) = i;
    }
}

bool UF::connected(int w, int v) {
    return find(w) == find(v);
}

void UF::Union(int w, int v) {
    int rootW = find(w);
    int rootV = find(v);
    if (rootV == rootW) return; //同一集合不用合并

    //把rank理解为合并次数，次数越多，集合越大，并让小的衣服大的
    if (m_rank->at(rootW) < m_rank->at(rootV)) {
        m_parent->at(rootW) = rootV;
    } else if (m_rank->at(rootW) > m_rank->at(rootV)) {
        m_parent->at(rootV) = rootW;
    } else {
        m_parent->at(rootV) = rootW;
        m_rank->at(rootW)++;
    }
    m_count--;
}

int UF::find(int p) {
    while (p != m_parent->(p)) {
        // 路径折半压缩
        m_parent->at(p) = (*m_parent)[m_parent->at(p)];
        p = m_parent->at(p);
    }
    return p;
}


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
