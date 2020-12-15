//
// Created by 左玉晖 on 2020/12/1.
// https://leetcode-cn.com/problems/rotate-list/
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        ListNode *old_tail = head;
        int n;
        for (n = 1; old_tail->next != NULL; n++) {
            old_tail = old_tail->next;
        }
        old_tail->next = head;

        ListNode *new_tail = head;
        for (int i = 0; i < n - k % n - 1; i++) {
            new_tail = new_tail->next;
        }
        ListNode *new_head = new_tail->next;
        new_tail->next = NULL;
        return new_head;
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
//    ListNode *l = sl.mergeInBetween(&listNode, &llistNode);
    return 0;
}

