/*
给你一个整数数组 nums ，你可以对它进行一些操作。
每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。

示例 1：
输入：nums = [3,4,2]
输出：6
解释：
删除 4 获得 4 个点数，因此 3 也被删除。
之后，删除 2 获得 2 个点数。总共获得 6 个点数。

示例 2：
输入：nums = [2,2,3,3,3,4]
输出：9
解释：
删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
总共获得 9 个点数。

提示：
1 <= nums.length <= 2 * 104
1 <= nums[i] <= 104
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pre = nums[0];
        int pre_cnt = 1;
        vector<int> new_nums;
        vector<int> new_sums;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                pre_cnt++;
                continue;
            }
            new_nums.push_back(pre);
            new_sums.push_back(pre * pre_cnt);
            pre = nums[i];
            pre_cnt = 1;
        }
        if (pre_cnt > 0) {
            new_nums.push_back(pre);
            new_sums.push_back(pre * pre_cnt);
        }
        vector<int> result(new_sums.size(), 0);
        result[0] = new_sums[0];
        if (new_sums.size() >= 2) {
            if (new_nums[1] == new_nums[0] + 1) {
                result[1] = max(new_sums[0], new_sums[1]);
            } else {
                result[1] = new_sums[0] + new_sums[1];
            }
        }
        for (int i = 2; i < new_sums.size(); i++) {
            if (new_nums[i] == new_nums[i - 1] + 1) {
                result[i] = max(result[i - 1], result[i - 2] + new_sums[i]);
            } else {
                result[i] = result[i - 1] + new_sums[i];
            }
        }
        return result[new_sums.size() - 1];
    }
};
