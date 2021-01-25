//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/course-schedule/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <queue>
#include <stack>

using namespace std;


class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v:edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) return;
            } else if (visited[v] == 1) {
                valid == false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (vector<int> pre:prerequisites) {
            edges[pre[1]].push_back(pre[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }

    vector<int> indeg;

    bool canFinish1(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);

        for (vector<int> pre:prerequisites) {
            edges[pre[1]].push_back(pre[0]);
            ++indeg[pre[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (edges[i] == 0) {
                q.push(i);
            }
        }
        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v:edges[u]) {
                --indeg[v];
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> arr1 = {2, 3};
    vector<int> arr2 = {3, 7};
    vector<int> arr3 = {4, 3};
    vector<int> arr4 = {3, 7};
    vector<vector<int>> sandwiches = {arr1, arr2, arr3, arr4};
}
/*
 * 根据上面的for循环的语法定义 ++i 和 i++的结果是一样的，都要等代码块执行完毕才能执行语句3，但是性能是不同的。在大量数据的时候++i的性能要比i++的性能好原因：

i++由于是在使用当前值之后再+1，所以需要一个临时的变量来转存。

而++i则是在直接+1，省去了对内存的操作的环节，相对而言能够提高性能*/