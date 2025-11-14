/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。

示例 3：
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。

提示：
3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        set<string> s;
        for (int i = 0; i < nums.size(); i++) {
            int aim = 0 - nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] == aim) {
                    string t = to_string(nums[i]) + "," + to_string(nums[l]) + "," + to_string(nums[r]);
                    if (s.find(t) != s.end()) {
                    } else {
                        vector<int> a({nums[i], nums[l], nums[r]});
                        result.push_back(a);
                        s.insert(t);
                    }
                    l++;
                    r--;
                    while (l >= 1 && l < nums.size() && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    while (r < nums.size() - 1 && r >= 0 && nums[r] == nums[r + 1]) {
                        r--;
                    }
                } else if (nums[l] + nums[r] > aim) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return result;
    }
};
