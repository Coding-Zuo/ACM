//
// Created by 左玉晖 on 2020/12/1.
// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

//(递归)
class Solution {
public:
    // 暴力法
    //对链表A中的每一个结点 ai​，遍历链表B 检查其中是否存在结点ai​。
    //时间复杂度O(m * n)   空间复杂度O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur_a = headA;
        while (cur_a) {
            ListNode *cur_b = headB;
            while (cur_b) {
                if (cur_a == cur_b) {
                    return cur_a;
                }
                cur_b = cur_b->next;
            }
            cur_a = cur_a->next;
        }
    }

    //哈希表法
//    使用一个hashset  遍历一个链表，hashset中存放其所有指针， 遍历另一个链表，去hashset中找相同指针
//    时间复杂度O(m + n)    空间复杂度O(m) 或 O(n)

    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> set;
        ListNode *cur_a = headA;
        while (cur_a) {
            set.insert(cur_a);
            cur_a = cur_a->next;
        }
        ListNode *cur_b = headB;
        while (cur_b) {
            if (set.find(cur_b) != set.end()) {
                return cur_b;
            }
            cur_b = cur_b->next;
        }
        return nullptr;
    }

/**
 * 方法三：双指针法

A的指针遍历完A 接着从headB开始遍历
B的指针遍历完B 接着从headA开始遍历
两个指针都最多走m + n。
当两个指针同时为空时，表示不相交；当两个都非空且相等时，表示相交

时间复杂度O(m + n)  空间复杂度O(1)
 */
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *cur_a = headA;
        ListNode *cur_b = headB;
        while (cur_a != cur_b) {
            cur_a = (cur_a ? cur_a->next : headB);
            cur_b = (cur_b ? cur_b->next : headB);
        }
        return cur_a;
    }
};


int main(int argc, const char *argv[]) {
    return 0;
}

