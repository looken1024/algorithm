/*
题目描述:输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

来源：力扣（LeetCode） 链接：https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof

解题思路：双指针

时间复杂度：O(N)

空间复杂度：O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> find_two_num(vector<int>& s, int sum) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        if (s[i] + s[j] == sum) {
            return vector<int>({s[i], s[j]});
        }
        if (s[i] + s[j] > sum) {
            j--;
        } else {
            i++;
        }
    }
    return vector<int>({-1, -1});
}

int main() {
    vector<int> s({1, 2, 4, 6, 7, 7, 9});
    vector<int> nums = find_two_num(s, 11);
    for (auto it : nums) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
