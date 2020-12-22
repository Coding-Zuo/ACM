//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/copy-list-with-random-pointer/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>

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
    Node *copyRandomList(Node *head) {
        if (head == NULL) {
            return NULL;
        }
        unordered_map<Node *, Node *> match;
        Node *pos = head;
        Node *newHead = new Node(head->val);
        Node *copy = newHead;
        while (pos) {
            //该循环匹配value和next
            match[pos] = copy;
            pos = pos->next;
            if (pos == NULL) {
                copy->next = nullptr;
                match[pos] = nullptr;
            } else {
                copy->next = new Node(pos->val);
            }
            copy = copy->next;
        }
        pos = head;
        copy = newHead;
        while (pos) {
            //匹配random
            copy->random = match[pos->random];
            copy = copy->next;
            pos = pos->next;
        }
        return newHead;

    }


};

int main(int argc, const char *argv[]) {
    Solution sl;
//    bool res = sl.isAnagram("nums", "sds");
    cout << 1;
    return 0;
}
