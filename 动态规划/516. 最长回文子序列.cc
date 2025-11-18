/*
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

示例 1：
输入：s = "bbbab"
输出：4
解释：一个可能的最长回文子序列为 "bbbb" 。

示例 2：
输入：s = "cbbd"
输出：2
解释：一个可能的最长回文子序列为 "bb" 。

提示：
1 <= s.length <= 1000
s 仅由小写英文字母组成
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int result = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = n; j >= i; j--) {
                if (s[i - 1] == s[j - 1]) {
                    if (j < n) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + (j > i ? 2 : 1));
                    } else {
                        dp[i][j] = max(dp[i][j], (j > i ? 2 : 1));
                    }
                } else if (j < n) {
                    dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j + 1]));
                } else {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};
