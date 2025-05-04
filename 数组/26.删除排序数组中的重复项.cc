/*
题目描述：给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。 延伸：如果是元素只要重复了，那么就将该重复的元素全部删除，这样的话又该怎么做呢？

来源：力扣（LeetCode） 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array

解题思路：双指针（快慢指针），如果快指针指向的值等于慢指针指向的值，那么快指针后移，否则给慢指针赋值后，快慢指针都后移。

时间复杂度：O(N)

空间复杂度：O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int unique(vector<int>& s) {
    int p = 0;
    s[p++] = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            continue;
        }
        s[p++] = s[i];
    }
    return p;
}

int main() {
    vector<int> s({1, 2, 3, 3, 3, 4, 6, 7, 7, 9});
    int len = unique(s);
    for (int i = 0; i < len; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}
