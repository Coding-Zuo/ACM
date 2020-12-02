cmake_minimum_required(VERSION 3.15)
project(ACM)

set(CMAKE_CXX_STANDARD 11)

add_executable(ACM main.cpp 模板.cpp)
add_executable(35 Leetcode/数组/35搜索插入位置.cpp)
add_executable(27 Leetcode/数组/27移除元素.cpp)
add_executable(15 Leetcode/数组/15三数之和.cpp)
add_executable(628 Leetcode/数组/628三个数的最大乘积.cpp)
add_executable(1 Leetcode/数组/1两数之和.cpp)
add_executable(18 Leetcode/数组/18四数之和.cpp)
add_executable(209 Leetcode/数组/209长度最小的子数组.cpp)
add_executable(18-2 Leetcode/数组/18四数之和2.cpp)
add_executable(59-2 Leetcode/数组/59螺旋矩阵.cpp)
add_executable(867 Leetcode/数组/867转置矩阵.cpp)
add_executable(1476 Leetcode/数组/1476子矩形查询.cpp)
add_executable(17.10 Leetcode/数组/17.10主要元素.cpp)
add_executable(1588 Leetcode/数组/1588所有奇数长度子数组的和.cpp)

add_executable(322 Leetcode/回溯/322重新安排行程.cpp)
add_executable(37 Leetcode/回溯/37解数独.cpp)


add_executable(206 Leetcode/链表/206翻转链表.cpp)
add_executable(142 Leetcode/链表/142环形链表2.cpp)
add_executable(203 Leetcode/链表/203移除元素.cpp)
add_executable(707 Leetcode/链表/707设计链表.cpp)


add_executable(LeastRecentlyUsedCache NowCoder/1Lru/LeastRecentlyUsedCache.cpp)
add_executable(N2 NowCoder/2直线过点.cpp)
add_executable(N3 NowCoder/3跳跃次数.cpp)
add_executable(N4 NowCoder/4返回两数组相加最大前k.cpp)

