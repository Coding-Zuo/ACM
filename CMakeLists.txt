cmake_minimum_required(VERSION 3.15)
project(ACM)

set(CMAKE_CXX_STANDARD 11)

add_executable(ACM main.cpp 模板.cpp)
add_executable(35 Leetcode/数组/35搜索插入位置.cpp)
add_executable(27 Leetcode/数组/27移除元素.cpp)
add_executable(15 Leetcode/数组/15三数之和.cpp)
add_executable(1 Leetcode/数组/1两数之和.cpp)
add_executable(18 Leetcode/数组/18四数之和.cpp)
add_executable(209 Leetcode/数组/209长度最小的子数组.cpp)
add_executable(18-2 Leetcode/数组/18四数之和2.cpp)
add_executable(322 Leetcode/回溯/322重新安排行程.cpp)


add_executable(206 Leetcode/链表/206翻转链表.cpp)
add_executable(142 Leetcode/链表/142环形链表2.cpp)


add_executable(LeastRecentlyUsedCache NowCoder/1Lru/LeastRecentlyUsedCache.cpp)

