//
// Created by 左玉晖 on 2020/12/1.
// https://leetcode-cn.com/problems/reverse-linked-list/
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

//(递归)
class Solution {
public:
    ListNode *reverse(ListNode *pre, ListNode *cur) {
        if (cur == NULL) return pre;
        ListNode *temp = cur->next;
        cur->next = pre;
        // pre = cur
        // cur = temp
        return reverse(cur, temp);
    }

    ListNode *reverseList(ListNode *head) {
        //cur=head;
        //pre=NUll
        return reverse(NULL, head);
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(int argc, const char *argv[]) {
    return 0;
}

