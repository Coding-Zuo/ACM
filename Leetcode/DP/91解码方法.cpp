//
// Created by 左玉晖 on 2020/11/21.
// https://leetcode-cn.com/problems/decode-ways/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <set>
#include <iomanip>

using namespace std;

/*
 * 确定状态
 * 解密数字串即划分成若干段数字，每段数字对应一个字母
 * 最后一步或最后一段：对应一个字母
 *
 * 子问题
 * 要求数字串前N个字符的解密方式
 * 需要知道数字串前N-1和N-2个字符的解密方式
 *
 * 转移方程
 * 状态：设数字串S前i个数字解密成字母串有f[i]种方式
 * f[i] = f[i-1]|S[i-1]对应一个字母 + f[i-2]|S[i-2]S[i-1]对应一个字母
 *
 *
 * 初始条件和边界情况
 * f[0]=1 即空串有1种方式解密 解密成空串
 * 边界：如果i=1，只看最后一个数字
 *
 * 计算顺序
 * f[0]...f[N]
 * 答案 f[N]
 * 时空O(N)
 */
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        int f[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = 0;
            //last digit
            int t = s[i - 1] - '0';
            if (t >= 1 && t <= 9) {
                f[i] += f[i - 1];
            }
            // last two digit
            if (i >= 2) {
                t = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if (t >= 10 && t <= 26) {
                    f[i] += f[i - 2];
                }
            }
        }
        return f[n];
    }
};

int main(int argc, const char *argv[]) {
    Solution sl;
    return 0;
}
