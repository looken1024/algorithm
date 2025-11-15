/*
给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。

示例 1：
输入：[3, 2, 1]
输出：1
解释：第三大的数是 1 。

示例 2：
输入：[1, 2]
输出：2
解释：第三大的数不存在, 所以返回最大的数 2 。

示例 3：
输入：[2, 2, 3, 1]
输出：1
解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。

提示：
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1

进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int> q;
        for (auto num : nums) {
            if (contain(q, num)) {
                continue;
            }
            q.push(num);
            if (q.size() > 3) {
                pop(q);
            }
        }
        if (q.size() == 3) {
            return tail(q);
        }
        return q.top();
    }

    bool contain(priority_queue<int> q, int num) {
        while (!q.empty()) {
            if (q.top() == num) {
                return true;
            }
            q.pop();
        }
        return false;
    }

    void pop(priority_queue<int>& q) {
        priority_queue<int> q2;
        while (!q.empty()) {
            int t = q.top();
            q.pop();
            if (!q.empty()) {
                q2.push(t);
            }
        }
        q = q2;
    }

    int tail(priority_queue<int> q) {
        while (!q.empty()) {
            int t = q.top();
            q.pop();
            if (q.empty()) {
                return t;
            }
        }
        return -1;
    }
};
