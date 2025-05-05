/*
题目地址
https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/

题目描述
复制
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。开始坐标总是小于结束坐标。平面内最多存在104个气球。

一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

Example:

输入:
[[10,16], [2,8], [1,6], [7,12]]

输出:
2

解释:
对于该样例，我们可以在x = 6（射爆[2,8],[1,6]两个气球）和 x = 11（射爆另外两个气球）。
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

int max_num(vector<vector<int>/**/>& s) {
    sort(s.begin(), s.end(), compare);
    int num = 0;
    vector<int> t(s.size(), 1);
    for (int i = 1; i < s.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (s[i][0] > s[j][1]) {
                t[i] = max(t[i], t[j] + 1);
                break;
            }
        }
        num = max(num, t[i]);
    }
    return num;
}

int main() {
    vector<vector<int>/**/> s({{10, 16}, {2, 8}, {1, 6}, {7, 12}});
    cout << max_num(s) << endl;
    return 0;
}
