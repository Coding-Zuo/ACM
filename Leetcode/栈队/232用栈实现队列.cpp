//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/implement-queue-using-stacks/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <queue>
#include <stack>

using namespace std;


class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> stak1; //push栈实现队列push操作
    stack<int> stak2; //pop栈实现队列pop操作
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        //直接将元素push进push栈stak1
        stak1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        //将stak1所有元素push进stak2,则stak2栈顶元素为队头元素
        while (!stak1.empty()) {
            stak2.push(stak1.top());
            stak1.pop();
        }

        //取队头元素，并将队头元素pop
        int s = stak2.top();
        stak2.pop();

        //将stak2中元素重新放回stak1中
        while (!stak2.empty()) {
            stak1.push(stak2.top());
            stak2.pop();
        }
        return s;
    }

    /** Get the front element. */
    int peek() {
        while (!stak1.empty()) {
            stak2.push(stak1.top());
            stak1.pop();
        }
        int s = stak2.top();

        while (!stak2.empty()) {
            stak1.push(stak2.top());
            stak2.pop();
        }
        return s;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stak1.empty() && stak2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


int main(int argc, const char *argv[]) {
    Solution sl;
    vector<int> arr1 = {2, 3};
    vector<int> arr2 = {3, 7};
    vector<int> arr3 = {4, 3};
    vector<int> arr4 = {3, 7};
    return 0;
}
