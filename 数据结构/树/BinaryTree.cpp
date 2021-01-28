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
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data) {}
};

class BinaryTree {
    Node *root;
    int size;
public:
    Node *add(Node *n, int data);

    int getSize(BinaryTree *bst);

    bool isEmpty(BinaryTree *bst);

    Node *newBinaryTre();

    void addRoot(int data);

    bool isIn(int data);

    bool _isIn(Node *n, int data);

    int findMax();

    Node *_findMax(Node *node);

    int findMin();

    Node *_findMin(Node *node);
};

// 新建一个二叉树
Node *BinaryTree::newBinaryTre() {
    BinaryTree *bst = new BinaryTree();
    bst->size = 0;
    bst->root = nullptr;
    return bst->root;
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
Node *BinaryTree::add(Node *n, int data) {
    if (n == nullptr) {
        this->size++;
        return new Node(data);
    } else {
        if (data < n->data) {
            n->left = this->add(n->left, data);
        } else if (data > n->data) {
            n->right = this->add(n->right, data);
        }
        return n;
    }

}

//根节点插入
void BinaryTree::addRoot(int data) {
    this->root = this->add(this->root, data);
}


//判断是否存在
bool BinaryTree::isIn(int data) {
    return this->_isIn(this->root, data);
}

bool BinaryTree::_isIn(Node *n, int data) {
    if (n == nullptr) {
        return false;
    }
    if (data == n->data) {
        return true;
    } else if (data < n->data) {
        return _isIn(n->left, data);
    } else {
        return _isIn(n->right, data);
    }
}

// 极大值
int BinaryTree::findMax() {
    if (this->size == 0) {
        return NULL;
    }
    Node *node = this->_findMax(this->root);
    return node->data;
}

Node *BinaryTree::_findMax(Node *node) {
    if (node->right == nullptr) {
        return node;
    } else {
        return _findMax(node->right);
    }
}

// 极小值
int BinaryTree::findMin() {
    if (this->size == 0) {
        return NULL;
    }
    Node *node = this->_findMin(this->root);
    return node->data;
}

Node *BinaryTree::_findMin(Node *node) {
    if (node->left == nullptr) {
        return node;
    } else {
        return _findMin(node->left);
    }
}

int main(int argc, const char *argv[]) {
    return 0;
}































