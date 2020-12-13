//
// Created by 左玉晖 on 2020/12/1.
// https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
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
    ListNode *getKthFromEnd(ListNode *head, int k) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        while (k--) {
            p2 = p2->next;
        }
        while (p2) {
            p2 = p2->next;
            p1 = p1->next;
        }
        return p1;
    }
};


int main(int argc, const char *argv[]) {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};
//    ListNode listNode(a[0]);
//    ListNode listNode1(a[1]);
//    ListNode listNode2(a[2]);
//    ListNode listNode3(a[3]);
//    ListNode listNode4(a[4]);
//    listNode.next = &listNode1;
//    listNode1.next = &listNode2;
//    listNode2.next = &listNode3;
//    listNode3.next = &listNode4;
//    ListNode llistNode(b[0]);
//    ListNode llistNode1(b[1]);
//    ListNode llistNode2(b[2]);
//    ListNode llistNode3(b[3]);
//    ListNode llistNode4(b[4]);
//    llistNode.next = &llistNode1;
//    llistNode1.next = &llistNode2;
//    llistNode2.next = &llistNode3;
//    llistNode3.next = &llistNode4;

    Solution sl;
//    ListNode *l = sl.mergeTwoLists(&listNode, &llistNode);
    return 0;
}

