/*
题目地址
https://leetcode-cn.com/problems/maximum-length-of-pair-chain/

题目描述
复制
给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。

现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。

给定一个对数集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。

示例 :

输入: [[1,2], [2,3], [3,4]]
输出: 2
解释: 最长的数对链是 [1,2] -> [3,4]
注意：

给出数对的个数在 [1, 1000] 范围内。
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

int max_pair(vector<vector<int>/**/>& s) {
    sort(s.begin(), s.end(), compare);
    vector<int> t(s.size(), 1);
    int len = 0;
    for (int i = 1; i < s.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (s[i][0] > s[j][1]) {
                t[i] = max(t[i], t[j] + 1);
            }
        }
        len = max(len, t[i]);
    }
    return len;
}

int main() {
    vector<vector<int>/**/> s({{1, 2}, {2, 3}, {3, 4}});
    cout << max_pair(s) << endl;
    return 0;
}
