/*
题目描述: 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。 说明： 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
来源：力扣（LeetCode） 链接：https://leetcode-cn.com/problems/merge-sorted-array

解题思路：双指针，两个指针从后往前移动即可。

时间复杂度：O(M+N)

空间复杂度：O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> combine(vector<int>& a, vector<int>& b) {
    vector<int> s;
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            s.push_back(a[i++]);
        }
        else {
            s.push_back(b[j++]);
        }
    }
    while (i < a.size()) {
        s.push_back(a[i++]);
    }
    while (j < b.size()) {
        s.push_back(b[j++]);
    }
    return s;
}

int main() {
    vector<int> a({1, 4, 5, 8, 9});
    vector<int> b({3, 4, 6, 7, 8});
    vector<int> s = combine(a, b);
    for (auto it : s) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
