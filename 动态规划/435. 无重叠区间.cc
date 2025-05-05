/*
题目地址
https://leetcode-cn.com/problems/non-overlapping-intervals/

题目描述
复制
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: [ [1,2], [1,2], [1,2] ]

输出: 2

解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: [ [1,2], [2,3] ]

输出: 0

解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareByAge(const vector<int>& a, const vector<int>& b) {
    return a[0] <= b[0];
}

int remove_num(vector<vector<int>/**/>& s) {
    sort(s.begin(), s.end(), compareByAge);
    int max_len = 0;
    vector<int> t(s.size(), 1);
    for (int i = 1; i < s.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (s[i][0] >= s[j][1]) {
                t[i] = max(t[i], t[j] + 1);
            }
        }
        max_len = max(max_len, t[i]);
    }
    return s.size() - max_len;
}

int main() {
    vector<vector<int>/**/> s({{1, 2}, {2, 3}, {3, 4}, {1, 3}});
    cout << remove_num(s) << endl;
    return 0;
}
