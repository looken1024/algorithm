/*
给你一个满足下述两条属性的 m x n 整数矩阵：
每行中的整数从左到右按非严格递增顺序排列。
每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

示例 1：
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true

示例 2：
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false

提示：
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x1 = 0;
        int x2 = matrix.size() - 1;
        while (x1 < x2) {
            int t = (x1 + x2) / 2;
            if (matrix[t][0] == target) {
                return true;
            }
            if (matrix[t][0] > target) {
                x2 = t;
            } else if (matrix[t][matrix[t].size() - 1] >= target) {
                x1 = t;
                break;
            } else {
                x1 = t + 1;
            }
        }
        int l = 0; 
        int r = matrix[x1].size() - 1;
        while (l < r) {
            int t = (l + r) / 2;
            if (matrix[x1][t] == target) {
                return true;
            }
            if (matrix[x1][t] > target) {
                r = t;
            } else {
                l = t + 1;
            }
        }
        return matrix[x1][l] == target;
    }
};
