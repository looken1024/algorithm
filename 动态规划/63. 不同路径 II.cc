/*
给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m - 1][n - 1]）。机器人每次只能向下或者向右移动一步。
网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。
返回机器人能够到达右下角的不同路径数量。
测试用例保证答案小于等于 2 * 10^9。

示例 1：
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

示例 2：
输入：obstacleGrid = [[0,1],[0,0]]
输出：1

提示：
m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] 为 0 或 1
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) {return 0;}
        if (obstacleGrid[0].empty()) {return 0;}
        if (obstacleGrid[0][0] == 1) {return 0;}
        vector<vector<int>> s(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        s[0][0] = 1;
        for (int i = 1; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0] == 0 && s[i - 1][0] == 1) {
                s[i][0] = 1;
            }
        }
        for (int i = 1; i < obstacleGrid[0].size(); i++) {
            if (obstacleGrid[0][i] == 0 && s[0][i - 1] == 1) {
                s[0][i] = 1;
            }
        }
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 1; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                s[i][j] = s[i - 1][j] + s[i][j - 1];
            }
        }
        return s[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> s(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            } else {
                s[i][0] = 1;
            }
        }
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1) {
                break;
            } else {
                s[0][j] = 1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    s[i][j] = 0;
                } else {
                    cout << i << ":" << j << endl;
                    s[i][j] = s[i - 1][j] + s[i][j - 1];
                }
            }
        }
        return s[m - 1][n - 1];
    }
};
