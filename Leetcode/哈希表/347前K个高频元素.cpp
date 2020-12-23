//
// Created by 左玉晖 on 2020/11/21.
//https://leetcode-cn.com/problems/top-k-frequent-elements/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    //自定义比较函数(小根堆)
    // 找出最高频次的k个元素，正好使用小根堆，因为要统计最大前k个元素，只有小顶堆每次将最小的元素弹出，最后小顶堆里积累的才是前k个最大元素。
    struct cmp {
        bool operator()(const pair<int, int> &m, const pair<int, int> &n) {
            return m.second > n.second;//小的优先级高
        }
    };

    vector<int> topKFrequent1(vector<int> &nums, int k) {
        unordered_map<int, int> cnt_dic;//map<nums[i],对应出现的次数>
        //定义一个小顶堆。priority_queue<Type,Container,Functional>
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> max_heap;
        vector<int> res; //保存结果
        for (auto &i:nums) {//统计出现频率
            cnt_dic[i]++;
        }
        // 用固定大小为k的小顶堆，扫面所有频率的数值
        // 在堆不断调整中，小的元素不断被弹出，剩下的就是最大的k个
        for (auto &iter:cnt_dic) {
            max_heap.push(iter);
            if (max_heap.size() > k) {
                //固定堆的大小为k
                max_heap.pop();
            }
        }
        //将堆中元素弹出到结果数组中
        for (int i = 0; i < k; i++) {
            res.push_back(max_heap.top().first);
            max_heap.pop();
        }
        return res;
    }

    void sift_up(vector<vector<int>> &heap, int chlid) {
        vector<int> val = heap[chlid];
        while (chlid >> 1 > 0 && val[1] < heap[chlid >> 1][1]) {
            heap[chlid] = heap[chlid >> 1];
            chlid >>= 1;
            heap[chlid] = val;
        }
    }

    void sift_down(vector<vector<int>> &heap, int root, int k) {
        vector<int> val = heap[root];
        while (root << 1 < k) {
            int chlid = root << 1;
            // 注意这里位运算优先级要加括号
            if ((chlid | 1) < k && heap[chlid | 1][1] < heap[chlid][1]) chlid |= 1;
            if (heap[chlid][1] < val[1]) {
                heap[root] = heap[chlid];
                root = chlid;
            } else break;
        }
        heap[root] = val;
    }


    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> stat;
        for (auto &num:nums) {
            stat[num]++;
        }
        vector<vector<int>> vec_stat;
        for (auto &item:stat) {
            vec_stat.push_back({item.first, item.second});
        }

        vector<vector<int>> heap;
        heap.push_back({0, 0});
        for (int i = 0; i < k; i++) {
            heap.push_back(vec_stat[i]);
            sift_up(heap, heap.size() - 1);
        }

        for (int i = k; i < vec_stat.size(); i++) {
            if (vec_stat[i][1] > heap[1][1]) {
                heap[1] = vec_stat[i];
                sift_down(heap, 1, k + 1);
            }
        }

        vector<int> result;
        for (int i = 1; i < k + 1; i++) {
            result.push_back(heap[i][0]);
        }
        return result;

    }

};

int main(int argc, const char *argv[]) {
    Solution sl;
//    bool res = sl.isAnagram("nums", "sds");
    cout << 1;
    return 0;
}

/*
 * 更新 0623： 更新为位操作，占位节点版本，简化的代码，方便记忆。

这题是对 堆，优先队列 很好的练习，因此有必要自己用python实现研究一下。堆 处理海量数据的 topK，分位数 非常合适，优先队列 应用在元素优先级排序，比如本题的频率排序非常合适。与基于比较的排序算法 时间复杂度 O(nlogn)O(nlogn) 相比，使用 堆，优先队列 复杂度可以下降到 O(nlogk)O(nlogk)，在总体数据规模 n 较大，而维护规模 k 较小时，时间复杂度优化明显。

堆，优先队列 的本质其实就是个完全二叉树，有其下重要性质
ps: 堆 heap[0] 插入一个占位节点，此时堆顶为 index 为 1 的位置，可以更方便的运用位操作。
[1,2,3] -> [0,1,2,3]

父节点 index 为 i
左子节点 index 为 i << 1
右子节点 index 为 i << 1 | 1
大顶堆中每个父节点大于子节点，小顶堆每个父节点小于子节点
优先队列以优先级为堆的排序依据
因为性质 1，2，3，堆可以用数组直接来表示，不需要通过链表建树。
堆，优先队列 有两个重要操作，时间复杂度均是 O(logk)O(logk)。以小顶锥为例：

上浮 sift up: 向堆尾新加入一个元素，堆规模 +1，依次向上与父节点比较，如小于父节点就交换。
下沉 sift down: 从堆顶取出一个元素（堆规模 -1，用于堆排序）或者更新堆中一个元素（本题），依次向下与子节点比较，如大于子节点就交换。
对于 topk 问题：最大堆求topk小，最小堆求 topk 大。

topk小：构建一个 k 个数的最大堆，当读取的数小于根节点时，替换根节点，重新塑造最大堆
topk大：构建一个 k 个数的最小堆，当读取的数大于根节点时，替换根节点，重新塑造最小堆
这一题的总体思路 总体时间复杂度 O(nlogk)O(nlogk)

遍历统计元素出现频率 O(n)O(n)
前k个数构造 规模为 k+1 的最小堆 minheap， O(k)O(k)， 注意 +1 是因为占位节点。
遍历规模k之外的数据，大于堆顶则入堆，下沉维护规模为k的最小堆 minheap. O(nlogk)O(nlogk)
(如需按频率输出，对规模为k的堆进行排序)

作者：xxinjiee
链接：https://leetcode-cn.com/problems/top-k-frequent-elements/solution/python-dui-pai-xu-by-xxinjiee/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * */
