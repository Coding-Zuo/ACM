//
// Created by 左玉晖 on 2020/12/1.
//https://leetcode-cn.com/problems/add-two-numbers-ii/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;//进位
        ListNode *ans = nullptr;
        while (!s2.empty() || !s1.empty() || carry != 0) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty())s1.pop();
            if (!s2.empty())s2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
            //头插法
            auto curnode = new ListNode(cur);
            curnode->next = ans;
            ans = curnode;
        }
        return ans;

    }
};


int main(int argc, const char *argv[]) {
    return 0;
}

