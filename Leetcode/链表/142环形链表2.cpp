//
// Created by 左玉晖 on 2020/11/23.
// https://leetcode-cn.com/problems/linked-list-cycle-ii/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *index1 = fast;
                ListNode *index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return NULL;
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    int a[5] = {1, 2, 3, 4, 5};
    ListNode listNode(a[0]);
    ListNode listNode1(a[1]);
    ListNode listNode2(a[2]);
    ListNode listNode3(a[3]);
    ListNode listNode4(a[4]);
    listNode.next = &listNode1;
    listNode1.next = &listNode2;
    listNode2.next = &listNode3;
    listNode3.next = &listNode4;

    ListNode *l = sl.detectCycle(&listNode);
    cout << 1;
    return 0;
}

/*
 *
 * slow指针走过的节点数为: x + y， fast指针走过的节点数：x + y + n (y + z)，n为fast指针在环内走了n圈才遇到slow指针， （y+z）为 一圈内节点的个数A。

因为fast指针是一步走两个节点，slow指针一步走一个节点， 所以 fast指针走过的节点数 = slow指针走过的节点数 * 2：

(x + y) * 2 = x + y + n (y + z)

两边消掉一个（x+y）: x + y = n (y + z)

因为要找环形的入口，那么要求的是x，因为x表示 头结点到 环形入口节点的的距离。

所以要求x ，将x单独放在左面：x = n (y + z) - y ,

再从n(y+z)中提出一个 （y+z）来，整理公式之后为如下公式：x = (n - 1) (y + z) + z 注意这里n一定是大于等于1的，因为 fast指针至少要多走一圈才能相遇slow指针。

这个公式说明什么呢？

先拿n为1的情况来举例，意味着fast指针在环形里转了一圈之后，就遇到了 slow指针了。

当 n为1的时候，公式就化解为 x = z，

这就意味着，「从头结点出发一个指针，从相遇节点 也出发一个指针，这两个指针每次只走一个节点， 那么当这两个指针相遇的时候就是 环形入口的节点」。

也就是在相遇节点处，定义一个指针index1，在头结点处定一个指针index2。

让index1和index2同时移动，每次移动一个节点， 那么他们相遇的地方就是 环形入口的节点。

那么 n如果大于1是什么情况呢，就是fast指针在环形转n圈之后才遇到 slow指针。

其实这种情况和n为1的时候 效果是一样的，一样可以通过这个方法找到 环形的入口节点，只不过，index1 指针在环里 多转了(n-1)圈，然后再遇到index2，相遇点依然是环形的入口节点。
 *
 * */