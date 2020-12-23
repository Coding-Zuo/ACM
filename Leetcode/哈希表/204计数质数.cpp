//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/count-primes/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isPrime(int x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {
        int ans = 0;
        for (int i = 2; i < n; i++) {
            ans += isPrime(i);
        }
        return ans;
    }

    int countPrimes1(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if ((long long) i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }

};

int main(int argc, const char *argv[]) {
    Solution sl;
//    bool res = sl.isAnagram("nums", "sds");
    cout << 1;
    return 0;
}
