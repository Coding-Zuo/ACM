//
// Created by 左玉晖 on 2020/11/21.
//https://leetcode-cn.com/problems/words-frequency-lcci/
#include <iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class WordsFrequency {
private:
    unordered_map<string, int> wordCount;
public:
    WordsFrequency(vector<string> &book) {
        if (book.size() != 0) {
            for (string str:book) {
                wordCount[str]++;
            }
        }
    }

    int get(string word) {
        if (wordCount.find(word) != wordCount.end()) {
            return wordCount[word];
        }
        return 0;
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */

int main(int argc, const char *argv[]) {
    Solution sl;
//    bool res = sl.isAnagram("nums", "sds");
    cout << 1;
    return 0;
}
