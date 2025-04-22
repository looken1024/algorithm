/*
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符

示例 1：
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

示例 2：
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 
提示：
0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if (len1 == 0) {return len2;}
        if (len2 == 0) {return len1;}
        vector<vector<int>> s(len1, vector<int>(len2, 0));
        s[0][0] = word1[0] == word2[0] ? 0 : 1;
        for (int i = 1; i < len1; i++) {
            if (word1[i] == word2[0]) {
                s[i][0] = i;
                continue;
            }
            s[i][0] = s[i - 1][0] + 1;
        }
        for (int i = 1; i < len2; i++) {
            if (word2[i] == word1[0]) {
                s[0][i] = i;
                continue;
            }
            s[0][i] = s[0][i - 1] + 1;
        }
        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {
                if (word1[i] == word2[j]) {
                    s[i][j] = s[i - 1][j - 1];
                    continue;
                }
                s[i][j] = min(min(s[i - 1][j - 1], s[i - 1][j]), s[i][j - 1]) + 1;
            }
        }
        return s[len1 - 1][len2 - 1];
    }
};
