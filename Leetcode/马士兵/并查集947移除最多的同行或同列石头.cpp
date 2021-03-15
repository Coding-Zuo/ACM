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

//并查集特殊模板2
class UnionFind {
    //本题因为是按行列进行查找，优化可以直接采用哈希表
public:
    // 哈希表映射关系[key,parent]
    unordered_map<int, int> parent;
    // 总共有多少不连通的并查集
    int count = 0;

    //并查集查找首领节点操作
    int Find(int index) {
        //一开始构建并查集时，假如key值不在并查集中则构建哈希表映射，count++
        if (parent.find(index) == parent.end()) {
            parent[index] = index;
            count++;
        }
        //查找并查集的首领节点并优化
        if (parent[index] != index) {
            parent[index] = Find(parent[index]);
        }
        return parent[index];
    }

    // 并查集合并操作
    void Uniod(int index1, int index2) {
        int parent1 = Find(index1);
        int parent2 = Find(index2);
        // 直接把两个首领一样的结果返回过滤，否则会让count多减1
        if (parent1 == parent2) {
            return;
        }
        parent[parent1] = parent2;
        count--;
    }

    // 思路：将石头行列的数值构建并查集，因此行或列需要加10001区分开
    // 合并的意思所有横坐标为 x 的石头和所有纵坐标为 y 的石头都属于同一个并查集
    // 最后返回石头数量 - 并查集的数量，就是题目要求的最多
    int removeStones(vector<vector<int>> &stones) {
        UnionFind uf;
        for (auto &stone:stones) {
            uf.Uniod(stone[0] + 10001, stone[1]);
        }
        return stones.size() - uf.count;
    }
};


class Solution {
private:
    int n = 20005;
    int father[20005];

    //并查集初始化
    void init() {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    //并查集里寻根过程
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    // 将v->u 这条边加入并查集
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }

    //判断u和v是否找到同一个根
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

public:
    int removeStones(vector<vector<int>> &stones) {
        init();
        for (int i = 0; i < stones.size(); i++) {
            join(stones[i][0], stones[i][1] + 10000);
        }
        unordered_map<int, bool> umap;
        for (int i = 0; i < stones.size(); i++) {
            umap[find(stones[i][0])] = true;
            umap[find(stones[i][1] + 10000)] = true;
        }
        return stones.size() - umap.size();
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
