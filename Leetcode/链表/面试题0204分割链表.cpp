//
// Created by 左玉晖 on 2020/12/1.
// https://leetcode-cn.com/problems/partition-list-lcci/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

//(递归)
class Solution {
public:
    //左边小于pivot 中间等于pivot 右边大于pivot
    void partition2(vector<ListNode *> &v, int x) {
        int less = -1;
        int more = v.size();

        int i = 0;
        while (i < more) {
            if (v.at(i)->val < x) {
                swap(v.at(i), v.at(++less));
            } else if (v.at(i)->val > x) {
                swap(v.at(i), v.at(--more));
                continue; //继续
            }
            ++i;
        }
    }

    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        vector<ListNode *> v;
        while (head) {
            v.push_back(head);
            head = head->next;
        }
        partition2(v, x);

        //建立新的链接
        for (int i = 0; i < (int) v.size() - 1; ++i) {
            v[i]->next = v[i + 1];
        }
        v[v.size() - 1]->next = NULL;

        return v[0];
    }
};


int main(int argc, const char *argv[]) {
    int a[6] = {1, 4, 3, 2, 5, 2};
    ListNode listNode(a[0]);
    ListNode listNode1(a[1]);
    ListNode listNode2(a[2]);
    ListNode listNode3(a[3]);
    ListNode listNode4(a[4]);
    ListNode listNode5(a[5]);
    listNode.next = &listNode1;
    listNode1.next = &listNode2;
    listNode2.next = &listNode3;
    listNode3.next = &listNode4;
    listNode4.next = &listNode5;
    Solution sl;
    ListNode *l = sl.partition(&listNode, 3);

    return 0;
}

