/*
给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]

示例 2：
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的

提示：
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
                while (i < nums1.size() && nums1[i] == nums1[i - 1]) {
                    i++;
                }
                while (j < nums2.size() && nums2[j] == nums2[j - 1]) {
                    j++;
                }
            } else if (nums1[i] < nums2[j]) {
                while (i < nums1.size() && nums1[i] < nums2[j]) {
                    i++;
                }
            } else if (nums1[i] > nums2[j]) {
                while (j < nums2.size() && nums1[i] > nums2[j]) {
                    j++;
                }
            }
        }
        return result;
    }
};
