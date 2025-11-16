/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例 1：
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]

示例 2：
输入：n = 1
输出：["()"]

提示：
1 <= n <= 8
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string tmp = "";
        process(result, tmp, n, 0, 0);
        return result;
    }

    void process(vector<string>& result, string tmp, int n, int left, int right) {
        if (left == n && right == n) {
            result.push_back(tmp);
            return;
        }
        if (left == n) {
            process(result, tmp + ')', n, left, right + 1);
            return;
        }
        if (left == right) {
            process(result, tmp + '(', n, left + 1, right);
            return;
        }
        if (left > right) {
            static vector<char> ss({'(', ')'});
            for (char c : ss) {
                if (c == '(') {
                    process(result, tmp + c, n, left + 1, right);
                } else {
                    process(result, tmp + c, n, left, right + 1);
                }
            }
        }
    }

};
