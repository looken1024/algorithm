/*
题目描述：给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode） 链接：https://leetcode-cn.com/problems/remove-element

解题思路：此题直接用双指针法解决。

时间复杂度：O(N)

空间复杂度：O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int remove(vector<int>& s, int target) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == target) {
            continue;
        }
        s[p++] = s[i];
    }
    return p;
}

int main() {
    vector<int> s({1, 3, 5, 7, 2, 5, 9});
    int len = remove(s, 5);
    for (int i = 0; i < len; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}
