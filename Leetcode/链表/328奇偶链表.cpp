//
// Created by 左玉晖 on 2020/12/1.
// https://leetcode-cn.com/problems/odd-even-linked-list/
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
    ListNode *oddEvenList(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *evenH = head;
        ListNode *evenHead = head->next;
        ListNode *oddHead = head;
        while (evenHead != NULL && evenHead->next != NULL) {
            oddHead->next = evenHead->next;
            oddHead = oddHead->next;
            evenHead->next = oddHead->next;
            evenHead = evenHead->next;
        }
        oddHead->next = evenH;
        return head;
    }
};

int main(int argc, const char *argv[]) {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    Solution sl;
    ListNode *ll = sl.oddEvenList(l1);

    return 0;
}

