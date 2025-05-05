/*
题目地址
https://leetcode-cn.com/problems/longest-increasing-subsequence

题目描述
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
*/

#include <iostream>
#include <vector>

using namespace std;

int max_len(vector<int>& s) {
    vector<int> t(s.size(), 1);
    int len = 0;
    for (int i = 1; i < s.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (s[i] > s[j]) {
                t[i] = max(t[j] + 1, t[i]);
            }
        }
        len = max(len, t[i]);
    }
    return len;
}

int main() {
    vector<int> s({10,9,2,5,3,7,101,18});
    cout << max_len(s) << endl;
    return 0;
}
