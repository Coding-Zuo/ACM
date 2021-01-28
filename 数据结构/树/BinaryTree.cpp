//
// Created by 左玉晖 on 2020/11/21.
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <iomanip>
#include <cstdio>

//func (variable_name variable_data_type) function_name() [return_type]{
//    /* 函数体*/
//}

using namespace std;

class Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data) {}
};

class BinaryTree {
    Node *root;
    int size;
public:
    Node *add(BinaryTree *bst, int data);

    int getSize(BinaryTree *bst);

    bool isEmpty(BinaryTree *bst);

    Node *newBinaryTre();

    void addRoot(int data);
};

// 新建一个二叉树
Node *BinaryTree::newBinaryTre() {
    BinaryTree *bst = new BinaryTree();
    bst->size = 0;
    bst->root = nullptr;
    return bst;
}

//获取二叉树大小
int BinaryTree::getSize(BinaryTree *bst) {
    return bst->size;
}

//判空
bool BinaryTree::isEmpty(BinaryTree *bst) {
    return bst->size == 0;
}

//插入
Node *BinaryTree::add(BinaryTree *bst, int data) {
    Node *n = bst->root;
    if (n == nullptr) {
        bst->size++;
        return new Node(data);
    } else {
        if (data < n->data) {
            n->left = bst->add(n->left, data);
        } else if (data > n->data) {
            n->right = bst->add(n->right, data);
        }
        return n;
    }

}

//根节点插入
void BinaryTree::addRoot(int data) {
    this->root = this->add(this->root, data);
}








































int main(int argc, const char *argv[]) {
    return 0;
}
