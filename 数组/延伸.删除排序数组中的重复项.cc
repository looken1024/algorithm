/*
题目描述：如果是元素只要重复了，那么就将该重复的元素全部删除，这样的话又该怎么做呢？

解法：

解题思路：双指针法，慢指针用于存储不重复的元素，快指针用于跳过重复的元素（快指针主要是跟指向的下一个元素比较）

时间复杂度：O(N)

空间复杂度：O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int remove_unique(vector<int>& s) {
    int p = 0;
    int l = 0;
    for (int r = 1; r < s.size(); r++) {
        if (s[l] == s[r]) {
            continue;
        }
        if (r - l > 1) {
            l = r;
            continue;
        }
        s[p++] = s[l];
        if (r == s.size() - 1 && r == l + 1) {
            s[p++] = s[r];
        }
        l = r;
    }
    return p;
}

int main() {
    vector<int> s({1, 2, 3, 3, 5, 7, 8, 8});
    int len = remove_unique(s);
    for (int i = 0; i < len; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}
