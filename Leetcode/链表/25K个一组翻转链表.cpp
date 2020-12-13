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

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode *, ListNode *> myReverse(ListNode *head, ListNode *tail) {
        ListNode *prev = tail->next;
        ListNode *p = head;
        while (prev != tail) {
            ListNode *nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *hair = new ListNode();
        hair->next = head;
        ListNode *pre = hair;

        while (head) {
            ListNode *tail = pre;
            //查看 剩余部分长度是否大于等于K
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode *nex = tail->next;
            pair<ListNode *, ListNode *> result = myReverse(head, tail);
            head = result.first;
            tail = result.second;
            //把子链表重新结回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return hair->next;
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

