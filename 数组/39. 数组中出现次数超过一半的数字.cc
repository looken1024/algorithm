/*
题目描述:数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

来源：力扣（LeetCode） 链接：https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof

解题思路：投票法，只需要进行一次遍历即可。先找出出现频率最高的数字，再判断该数字的出现频率是否超过数组的一半。

时间复杂度：O(N)

空间复杂度：O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int get_num(vector<int>& s) {
    int pre = s[0];
    int v = 1;
    for (int i = 1; i < s.size(); i++) {
        if (pre == s[i]) {
            v++;
            continue;
        }
        v--;
        if (v == 0) {
            v++;
            pre = s[i];
        }
    }
    return pre;
}

int main() {
    vector<int> s({1, 2, 3, 3, 3, 2, 2, 2, 2});
    int num = get_num(s);
    cout << num << endl;
    return 0;
}
