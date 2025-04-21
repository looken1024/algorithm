/*
给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。

示例 1:
输入: nums = [2,2,3,4]
输出: 3
解释:有效的组合是: 
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3

示例 2:
输入: nums = [4,2,3,4]
输出: 4
 
提示:
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
*/

// 暴力，超时了
class Solution {
public:
    inline bool canMakeTriangle(int a, int b, int c) {
        return a + b > c && a + c > b && b + c > a;
    }
    int triangleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (canMakeTriangle(nums[i], nums[j], nums[k])) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                int s = nums[i] + nums[j];
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r) {
                    int m = (l + r + 1) / 2;
                    if (nums[m] >= s) {
                        r = m - 1;
                    } else {
                        l = m;
                    }
                }
                if (nums[r] < s) {
                    result += (r - j);
                }
            }
        }
        return result;
    }
};