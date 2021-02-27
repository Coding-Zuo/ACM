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

    int getSize();

    bool isEmpty(BinaryTree *bst);

    Node *newBinaryTre();

    void addRoot(int data);

    bool isIn(int data);

    bool _isIn(Node *n, int data);

    int findMax();

    Node *_findMax(Node *node);

    int findMin();

    Node *_findMin(Node *node);

    void preOrder();

    void _preOrder(Node *node);

    void inOrder();

    void _inOrder(Node *node);

    void postOrder();

    void _postOrder(Node *node);

    Node *getRoot() {
        return this->root;
    }

    void *setRoot(Node *node) {
        this->root = node;
    }

    //打印树形
    string show(Node *node, int depth, string res);
};

// 新建一个二叉树
Node *BinaryTree::newBinaryTre() {
    BinaryTree *bst = new BinaryTree();
    bst->size = 0;
    bst->root = nullptr;
    return bst->root;
}

//获取二叉树大小
int BinaryTree::getSize() {
    return this->size;
}

//判空
bool BinaryTree::isEmpty(BinaryTree *bst) {
    return bst->size == 0;
}

//插入
Node *BinaryTree::add(Node *n, int data1) {
    if (n == NULL) {
        this->size++;
        return new Node(data1);
    }

    if (data1 < n->data) {
        n->left = this->add(n->left, data1);
    } else if (data1 > n->data) {
        n->right = this->add(n->right, data1);
    }
    return n;
}

//根节点插入
void BinaryTree::addRoot(int data) {
    this->root = add(root, data);
}


//判断是否存在
bool BinaryTree::isIn(int data) {
    return this->_isIn(root, data);
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

void BinaryTree::preOrder() {
    _preOrder(this->root);
}

void BinaryTree::_preOrder(Node *node) {
    if (node != nullptr) {
        cout << node->data << endl;
        _preOrder(node->left);
        _preOrder(node->right);
    }
}

void BinaryTree::inOrder() {
    _inOrder(this->root);
}

void BinaryTree::_inOrder(Node *node) {
    if (node != nullptr) {
        _preOrder(node->left);
        cout << node->data << endl;
        _preOrder(node->right);
    }
}

void BinaryTree::postOrder() {
    _postOrder(this->root);
}

void BinaryTree::_postOrder(Node *node) {
    if (node != nullptr) {
        _preOrder(node->left);
        _preOrder(node->right);
        cout << node->data << endl;
    }
}

string BinaryTree::show(Node *node, int depth, string res) {
    if (node == NULL) return "";
    show(node->left, depth + 1, res);
    for (int i = 0; i < depth; i++) {
        res += "  ";
    }
    res += node->data;
    show(node->right, depth + 1, res);
}


int main(int argc, const char *argv[]) {
    BinaryTree *binaryTree = new BinaryTree();

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(5);
    Node *node4 = new Node(6);
    Node *node5 = new Node(7);
    binaryTree->setRoot(node3);
    node3->right = node2;
    node3->left = node1;
    Node *n[4] = {node2, node3, node4, node5};
    vector<Node *> v1(n, n + sizeof(n) / sizeof(int));

    string s = binaryTree->show(binaryTree->getRoot(), 2, "");
    cout << s;
    return 0;
}































