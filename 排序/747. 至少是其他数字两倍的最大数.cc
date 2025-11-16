/*
给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。
请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则返回 最大元素的下标 ，否则返回 -1 。

示例 1：
输入：nums = [3,6,1,0]
输出：1
解释：6 是最大的整数，对于数组中的其他整数，6 至少是数组中其他元素的两倍。6 的下标是 1 ，所以返回 1 。

示例 2：
输入：nums = [1,2,3,4]
输出：-1
解释：4 没有超过 3 的两倍大，所以返回 -1 。

提示：
2 <= nums.length <= 50
0 <= nums[i] <= 100
nums 中的最大元素是唯一的
*/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> index;
        for (int i = 0; i < nums.size(); i++) {
            index.push_back(i);
        }
        sort(index.begin(), index.end(), [&nums](int a, int b) {
            return nums[a] >= nums[b];
        });
        return nums[index[0]] >= 2 * nums[index[1]] ? index[0] : -1;
    }
};
