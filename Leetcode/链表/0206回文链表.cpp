//
// Created by 左玉晖 on 2020/12/1.
// https://leetcode-cn.com/problems/palindrome-linked-list-lcci/
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
    bool isPalindromeStack(ListNode *head) {
        stack<int> temp;
        ListNode *p = head;
        bool res = true;
        while (p != nullptr) {
            temp.push(p->val);
            p = p->next;
        }
        ListNode *q = head;
        while (q != nullptr) {
            if (q->val != temp.top()) {
                return false;
            } else {
                q = q->next;
                temp.pop();
            }
        }
        return res;
    }

    bool isPalindrome(ListNode *head) {
        //快慢指针
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL; //维护prev为slow的前一个元素（在原链表中）
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }//循环后 原链表被分为两段，两段的头分别是prev和slow
        if (fast) slow = slow->next;//当长度为2n+1时，循环后fast为最后元素，slow为n+1个元素。
//        起始比较点从slow->next开始（第n+2个元素）。当
//        长度为2n时，循环后fast为NULL，slow为第n+1个元素，起始比较点从slow开始，故不操作。
        while (prev && slow) {
            if (prev->val != slow->val) {
                return false;
            }
            prev = prev->next;
            slow = slow->next;
        }
        return true;

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
    bool res = sl.isPalindrome(l1);

    return 0;
}

