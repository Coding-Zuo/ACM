//
// Created by 左玉晖 on 2020/12/1.
// https://leetcode-cn.com/problems/merge-two-sorted-lists/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <numeric>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *resHead = new ListNode(-1);
        ListNode *prev = resHead;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                prev->next = l2;
                l2 = l2->next;
            } else {
                prev->next = l1;
                l1 = l1->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return resHead->next;

    }

    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

};

int main(int argc, const char *argv[]) {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};
    ListNode listNode(a[0]);
    ListNode listNode1(a[1]);
    ListNode listNode2(a[2]);
    ListNode listNode3(a[3]);
    ListNode listNode4(a[4]);
    listNode.next = &listNode1;
    listNode1.next = &listNode2;
    listNode2.next = &listNode3;
    listNode3.next = &listNode4;
    ListNode llistNode(b[0]);
    ListNode llistNode1(b[1]);
    ListNode llistNode2(b[2]);
    ListNode llistNode3(b[3]);
    ListNode llistNode4(b[4]);
    llistNode.next = &llistNode1;
    llistNode1.next = &llistNode2;
    llistNode2.next = &llistNode3;
    llistNode3.next = &llistNode4;

    Solution sl;
    ListNode *l = sl.mergeTwoLists(&listNode, &llistNode);
    return 0;
}

