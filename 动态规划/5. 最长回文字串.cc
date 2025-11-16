/*
给你一个字符串 s，找到 s 中最长的 回文 子串。

示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

示例 2：
输入：s = "cbbd"
输出："bb"
 
提示：
1 <= s.length <= 1000
s 仅由数字和英文字母组成
*/

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> m(s.size() + 2, vector<int>(s.size() + 2, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = s.size(); j >= i; j--) {
                if (s[i - 1] == s[j - 1]) {
                    m[i][j] = max(m[i][j], m[i - 1][j + 1] + (i == j ? 1 : 2));
                }
            }
        }
        int r = 0;
        int r_i;
        int r_j;
        for (int i = 1; i <= s.size(); i++) {
            if (m[i][i] > r) {
                r = m[i][i];
                r_i = i - m[i][i] / 2 - 1;
                r_j = i + m[i][i] / 2 - 1;
            }
        }
        for (int i = 1; i < s.size(); i++) {
            if (m[i][i + 1] > r) {
                r = m[i][i + 1];
                r_i = i - m[i][i + 1] / 2;
                r_j = i + m[i][i + 1] / 2 - 1;
            }
        }
        string result = "";
        for (int i = r_i; i <= r_j; i++) {
            result += s[i];
        }
        return result;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> d(s.size() + 2, vector<int>(s.size() + 2, 0));
        string result = "";
        int max_len = 0;
        int pos = -1;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = s.size(); j > i; j--) {
                if (s[i - 1] == s[j - 1]) {
                    d[i][j] = max(d[i][j], d[i - 1][j + 1] + 2);
                }
            }
            d[i][i] = max(d[i][i], d[i - 1][i + 1] + 1);
        }
        for (int i = 1; i <= s.size(); i++) {
            if (d[i][i] > max_len) {
                max_len = d[i][i];
                pos = i - 1 - (max_len - 1) / 2;
            }
            if (d[i - 1][i] > max_len) {
                max_len = d[i - 1][i];
                pos = i - 1 - max_len / 2;
            }
        }
        cout << pos << ", " << max_len << endl;
        return s.substr(pos, max_len);
    }
};
