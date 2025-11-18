/*
给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。
下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。

示例 1：
输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
输出：13

示例 2：
输入：matrix = [[-19,57],[-40,-5]]
输出：-59

提示：
n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> s(m, vector<int>(n, 0));
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            s[0][i] = matrix[0][i];
            if (m == 1) {
                result = min(result, s[0][i]);
            }
        }
        if (result != INT_MAX) {
            return result;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    s[i][j] = min(s[i - 1][j], s[i - 1][j + 1]) + matrix[i][j];
                } else if (j == n - 1) {
                    s[i][j] = min(s[i - 1][j - 1], s[i - 1][j]) + matrix[i][j];
                } else {
                    s[i][j] = min(s[i - 1][j - 1], min(s[i - 1][j], s[i - 1][j + 1])) + matrix[i][j];
                }
                if (i == m - 1) {
                    result = min(result, s[i][j]);
                }
            }
        }
        return result;
    }
};
