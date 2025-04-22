/*
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。

示例 1：
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。

示例 2：
输入：grid = [[1,2,3],[4,5,6]]
输出：12

提示：
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> s(grid.size(), vector<int>(grid[0].size(), 0));
        s[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++) {
            s[i][0] = s[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < grid[0].size(); i++) {
            s[0][i] = s[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                s[i][j] = min(s[i - 1][j], s[i][j - 1]) + grid[i][j];
            }
        }
        return s[grid.size() - 1][grid[0].size() - 1];
    }
};
