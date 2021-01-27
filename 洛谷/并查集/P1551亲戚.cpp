//
// Created by 左玉晖 on 2020/11/21.
// https://zhuanlan.zhihu.com/p/93647900/
// https://www.luogu.com.cn/problem/P1551
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <iomanip>
#include <cstdio>

using namespace std;
#define MAXN 5005
int fa[MAXN], rank1[MAXN];

inline void init(int n) {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        rank1[i] = 1;
    }
}

int find(int x) { //找出x家的大佬 也就是二叉树的祖先节点
    if (x == fa[x])
        return x;  //他是家里最大的大佬，所以返回的x就是我们所求的祖先节点
    else {
        fa[x] = find(fa[x]);  //父节点设为根节点
        return fa[x];         //返回父节点
        //x不是他自己的爸爸，所以他上面还
        //有爸爸，我们的目标是祖先节点，所以我们此时要做的是问他
        //爸爸的爸爸是谁，即再使用一次fd（find）函数【其实就是一个递归过程
    }
}

inline void merge(int i, int j) {
    int x = find(i), y = find(j);
    if (rank1[x] <= rank1[y]) {
        fa[x] = y;
    } else {
        fa[y] = x;
    }
    if (rank1[x] == rank1[y] && x != y) {
        rank1[y]++;
    }
}


int main(int argc, const char *argv[]) {
//    int n, m, p, x, y;
//    scanf("%d%d%d", &n, &m, &p);
//    init(n);
//    for (int i = 0; i < m; ++i) {
//        scanf("%d%d", &x, &y);
//        merge(x, y);
//    }
//    for (int i = 0; i < p; ++i) {
//        scanf("%d%d", &x, &y);
//        printf("%s\n", find(x) == find(y) ? "Yes" : "No");
//    }
    int n, m, p, x, y;
    cin >> n >> m >> p;
    init(n);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        merge(x, y);
    }
    for (int i = 0; i < p; ++i) {
        cin >> x >> y;
        if (find(x) == find(y)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
