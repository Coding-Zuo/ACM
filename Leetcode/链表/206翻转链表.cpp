//
// Created by 左玉晖 on 2020/11/23.
// https://leetcode-cn.com/problems/reverse-linked-list/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *cur = head;
        ListNode *pre = NULL;
        ListNode *temp;
        while (cur != NULL) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    ListNode *reverseList1(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *ret = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return ret;
    }

    ListNode *reverseList2(ListNode *head) {
        if (head == NULL) { return NULL; }
        ListNode *cur = head;
        while (head->next != NULL) {
            ListNode *t = head->next->next;
            head->next->next = cur;
            cur = head->next;
            head->next = t;
        }
        return cur;
    }


};


int main(int argc, const char *argv[]) {
    Solution sl;
    int a[5] = {1, 2, 3, 4, 5};
    ListNode listNode(a[0]);
    ListNode listNode1(a[1]);
    ListNode listNode2(a[2]);
    ListNode listNode3(a[3]);
    ListNode listNode4(a[4]);
    listNode.next = &listNode1;
    listNode1.next = &listNode2;
    listNode2.next = &listNode3;
    listNode3.next = &listNode4;

    ListNode *l = sl.reverseList(&listNode);
    cout << 1;
    return 0;
}
