//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/maximum-number-of-eaten-apples/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <queue>

using namespace std;

struct node {
    // cnt代表个数，idx代表过期时间
    int cnt, idx;

    node() {}

    node(int cnt_, int idx_) : cnt(cnt_), idx(idx_) {}

    bool operator<(const node &rhs) const {
        return idx > rhs.idx;
    }
};

class Solution {
public:
    int eatenApples(vector<int> &apples, vector<int> &days) {
        int n = apples.size();
        int ans = 0;
        priority_queue<node> pq;
        int i = 0;
        int nn = n;//定义可变右边界
        while (i < nn) {
            while (!pq.empty() && pq.top().idx <= i) {
                //移除掉烂苹果
                pq.pop();
            }
            if (i < n && apples[i] > 0) {
                // 添加有效苹果到优先队列
                pq.push(node(apples[i], i + days[i]));
                nn = max(nn, i + days[i] + 1);//比较，获得较大右边界
            }
            if (!pq.empty()) {
                node now = pq.top();//拿出靠前的一堆苹果吃掉
                pq.pop();
                now.cnt -= 1;
                ans++;
                if (now.cnt > 0) {
                    //如果这堆苹果没吃完放回去
                    pq.push(now);
                }
            }
            i++;
        }
        return ans;
    }
};


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    bool res = sl.halvesAreAlike("booksa");
    cout << res;
    return 0;
}
