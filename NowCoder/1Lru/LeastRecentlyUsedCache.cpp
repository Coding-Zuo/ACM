//
// Created by 左玉晖 on 2020/11/22.
//

#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

template<class K, class V>
struct Node {
    K key;
    V value;
    Node *next, *last;

    Node(K k, V v) : key(k), value(v), last(NULL), next(NULL) {}
};

//双向链表+哈希表结构的
//template<class K, class V>
//struct NodeDoubleLinkedList {
//    Node<K, V> *head;
//    Node<K, V> *tail;
//
//    NodeDoubleLinkedList(Node<K, V> *head, Node<K, V> *tail) : head(head), tail(tail) {}
//};

template<class K, class V>
class NodeDoubleLinkedList {
public:
    Node<K, V> *head;
    Node<K, V> *tail;

    NodeDoubleLinkedList() {}

    NodeDoubleLinkedList(Node<K, V> *head, Node<K, V> *tail) : head(head), tail(tail) {}

    //添加新节点。放到尾巴上
    void addNode(Node<K, V> *newNode) {
        if (newNode == NULL) {
            return;
        }
        if (this->head == NULL) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->next = newNode;
            newNode->last = this->tail;
            this->tail = newNode;
        }
    }

    /*
     * 潜台词：双向链表上一定有这node
     * node分离出，但是node前后环境重新连接
     * node放到尾巴上
     */
    void moveNodeToTail(Node<K, V> *node) {
        if (this->tail == node) {
            return;
        }
        if (this->head == node) {
            this->head = node->next;
            this->head->last = node->last;
        } else { //当前node是中间的一个节点
            node->last->next = node->next;
            node->last->last = node->last;
        }
        node.last = this->tail;
        node.next = NULL;
        this->tail->next = node;
        this->tail = node;
    }

    Node<K, V> *removeHead() {
        if (this->head == NULL) {
            return nullptr;
        }
        Node<K, V> *res = this->head;
        if (this->head == this->tail) {
            this->head = NULL;
            this->tail = NULL;
        } else {
            this->head = res->next;
            res->next = NULL;
            this->head->last = NULL;
        }
        return res;
    }

};

template<class K, class V>
class MyCache {
public:
    unordered_map<K, Node<K, V>> keyNodeMap;
    NodeDoubleLinkedList<K, V> nodeList;
    int capacity;

    MyCache(int capacity) {
        this->capacity = capacity;
        this->nodeList = new NodeDoubleLinkedList<K, V>();
        this->keyNodeMap = new unordered_map<K, Node<K, V>>();
    }

    V get(K key) {
        if (this->keyNodeMap.find(key) != keyNodeMap.end()) {
            Node<K, V> res = this->keyNodeMap[key];
            this->nodeList.moveNodeToTail(&res);
            return res.value;
        }
    }

    void set(K key, V value) {
        if (this->keyNodeMap.find(key) != this->keyNodeMap.end()) {
            Node<K, V> node = this->keyNodeMap[key];
            node.value = value;
            this->nodeList.moveNodeToTail(&node);
        } else { //新加的记录，有可能出现替换
            Node<K, V> *newNode(key, value);
            this->keyNodeMap.insert(key, newNode);
            this->nodeList.addNode(newNode);
            if (this->keyNodeMap.size() == this->capacity + 1) {
                this->removeMostUnusedCache();
            }
        }
    }

    void removeMostUnusedCache() {
//        Node<K, V> removeNode = this->nodeList.removeHead();
        this->keyNodeMap.erase(this->nodeList.removeHead()->key);
    }
};

int main(int argc, const char *argv[]) {
    MyCache<string, int> myCache(3);
    myCache.set("A", 1);
    myCache.set("B", 2);
    myCache.set("C", 3);
    cout << myCache.get("A");
    return 0;
}