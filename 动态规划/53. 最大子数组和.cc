/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组是数组中的一个连续部分。

示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

示例 2：
输入：nums = [1]
输出：1

示例 3：
输入：nums = [5,4,-1,7,8]
输出：23
 
提示：
1 <= nums.length <= 10^5
-104 <= nums[i] <= 10^4
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        for (int i = 0; i < nums.size(); i++) {
            result = max(result, nums[i]);
        }
        int tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (tmp < 0) {
                tmp = 0;
            }
            tmp += nums[i];
            result = max(result, tmp);
        }
        return result;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = max_vlaue(nums);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
                result = max(result, sum);
            }
        }
        return result;
    }

    int max_vlaue(vector<int>& nums) {
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            result = max(result, nums[i]);
        }
        return result;
    }
};
