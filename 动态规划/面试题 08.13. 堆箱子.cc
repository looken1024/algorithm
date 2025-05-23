/*
堆箱子。给你一堆n个箱子，箱子宽 wi、深 di、高 hi。箱子不能翻转，将箱子堆起来时，下面箱子的宽度、高度和深度必须大于上面的箱子。实现一种方法，搭出最高的一堆箱子。箱堆的高度为每个箱子高度的总和。

输入使用数组[wi, di, hi]表示每个箱子。

示例 1：
输入：box = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
输出：6

示例 2：
输入：box = [[1, 1, 1], [2, 3, 4], [2, 6, 7], [3, 4, 5]]
输出：10
提示:

箱子的数目不大于3000个。
*/

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0] && a[1] == b[1]) {
            return a[2] > b[2];
        }
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] > b[0];
    }
    int pileBox(vector<vector<int>>& box) {
        sort(box.begin(), box.end(), compare);
        vector<int> s(box.size(), 0);
        for (int i = 0; i < box.size(); i++) {
            s[i] = box[i][2];
        }
        int r = 0;
        for (int i = 1; i < box.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (box[i][0] < box[j][0] && box[i][1] < box[j][1] && box[i][2] < box[j][2]) {
                    s[i] = max(s[i], s[j] + box[i][2]);
                }
            }
            r = max(r, s[i]);
        }
        return r;
    }
};
