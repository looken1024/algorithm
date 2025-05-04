/*
题目描述：给定一个增序排列数组 nums ，你需要在 原地 删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

来源：力扣（LeetCode） 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii

解题思路：该题用双指针法解决，需要判断慢指针前面的情况，分为这三种情况：快指针和慢指针值不同，快慢指针值相同并且慢指针前后值相同，快慢指针值不同且慢指针前后值不同。

时间复杂度：O(N)

空间复杂度：O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int remove(vector<int>& s) {
    int p = 0;
    int l = 0;
    for (int r = 1; r < s.size(); r++) {
        if (s[l] == s[r]) {
            if (r == s.size() - 1) {
                for (int j = 0; j < min(2, r - l); j++) {
                    s[p++] = s[l + j];
                }
            }
            continue;
        }
        for (int j = 0; j < min(2, r - l); j++) {
            s[p++] = s[l + j];
        }
        if (r == s.size() - 1) {
            s[p++] = s[r];
        }
        l = r;
    }
    return p;
}

int main() {
    vector<int> s({1, 2, 3, 3, 4, 5, 5, 5, 5, 7, 7, 8, 8, 8, 8});
    int len = remove(s);
    for (int i = 0; i < len; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}
