//
// Created by 左玉晖 on 2020/12/1.
// https://leetcode-cn.com/problems/remove-linked-list-elements/
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
    ListNode *removeElements(ListNode *head, int val) {
        while (head != NULL && head->val == val) {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        ListNode *cur = head;
        while (cur != NULL && cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }

    ListNode *removeElements1(ListNode *head, int val) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};

int main(int argc, const char *argv[]) {
    return 0;
}

