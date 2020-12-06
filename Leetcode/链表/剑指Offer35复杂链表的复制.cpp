//
// Created by 左玉晖 on 2020/12/1.
// https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
//    Node *copyRandomList(Node *head) {
//        Node* cur = head;
//        Node* dum = new Node(0);
//        Node* pre = dum;
//        while(cur!= nullptr){
//            Node* node = new Node(cur->val);
//            pre->next=node;
//            //pre->ramdom=???
//            cur=cur->next;
//            pre=node;
//        }
//    }
    Node *copyRandomList(Node *head) {
        if (head == nullptr) return nullptr;
        Node *cur = head;
        unordered_map<Node *, Node *> map;
        while (cur != nullptr) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
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

