//
// Created by 左玉晖 on 2020/12/1.
// https://leetcode-cn.com/problems/merge-in-between-linked-lists/
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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        ListNode *pos = list1;
        ListNode *dummy = new ListNode(0);//辅助头结点，方便统一处理节点
        dummy->next = list1; //将辅助头结点放到链表1的前面
        ListNode *pre = dummy;
        while (a) {
            --a;
            --b;
            pre = pos;
            pos = pos->next;
        }
        pre->next = list2;//将链表2的头结点链接到链表1的
        pre = pos; //方便后面释放删除掉的节点内存
        while (b) {
            --b;
            pos = pos->next;
        }
        while (list2->next) {
            list2 = list2->next;
        }
        list2->next = pos->next; //将链表2的尾结点链接到链表1的第二个位置
        pos->next = nullptr;
        while (pre) {
            pos = pre->next;
            delete pre;
            pre = pos;
        }
        delete dummy;
        return list1;
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
    ListNode *l = sl.mergeInBetween(&listNode, &llistNode);
    return 0;
}

