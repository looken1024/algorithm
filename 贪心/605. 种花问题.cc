/*
假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false 。

示例 1：
输入：flowerbed = [1,0,0,0,1], n = 1
输出：true

示例 2：
输入：flowerbed = [1,0,0,0,1], n = 2
输出：false

提示：
1 <= flowerbed.length <= 2 * 104
flowerbed[i] 为 0 或 1
flowerbed 中不存在相邻的两朵花
0 <= n <= flowerbed.length
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> tmp;
        tmp.push_back(0);
        for (auto it : flowerbed) {
            tmp.push_back(it);
        }
        tmp.push_back(0);
        int sum = 0;
        int pre = tmp[0];
        int pre_num = 1;
        int i = 1;
        for (; i < tmp.size(); i++) {
            if (tmp[i] == pre) {
                pre_num++;
                continue;
            }
            if (pre == 0) {
                sum += (pre_num >= 3 ? (pre_num - 1) / 2: 0);
                pre = 1;
            } else {
                pre = 0;
            }
            pre_num = 1;
        }
        if (i == tmp.size() && pre == 0) {
            sum += (pre_num >= 3 ? (pre_num - 1) / 2: 0);
        }
        return sum >= n;
    }
};