/*
题目：二维数组中，每行从左到右递增，每列从上到下递增，给出一个数，判断它是否在数组中
思路：从左下角或者右上角开始比较
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>/**/>& matrix, int target) {
        int x1 = matrix.size() - 1, y1 = 0;
        int x2 = 0, y2 = matrix[0].size() - 1;
        int pre1 = x1, pre2 = x2, pre3 = y1, pre4 = y2;
        while (x2 <= x1 && y1 <= y2) {
            while (x1 > 0 && matrix[x1][y1] > target) {
                x1--;
            }
            while (y1 < matrix[0].size() - 1 && matrix[x1][y1] < target) {
                y1++;
            }
            if (matrix[x1][y1] == target) {
                return true;
            }
            while (y2 > 0 && matrix[x2][y2] > target) {
                y2--;
            }
            while (x2 < matrix.size() - 1 && matrix[x2][y2] < target) {
                x2++;
            }
            if (matrix[x2][y2] == target) {
                return true;
            }
            if (x1 == pre1 && x2 == pre2 && y1 == pre3 && y2 == pre4) {
                break;
            }
            pre1 = x1;
            pre2 = x2;
            pre3 = y1;
            pre4 = y2;
        }
        if (matrix[x1][y1] == target || matrix[x2][y2] == target) {
            return true;
        }
        return false;
    }
};

int main() {
    vector<vector<int>/**/> matrix;
    matrix.push_back(vector<int>({1,4,7,11,15}));
    matrix.push_back(vector<int>({2,5,8,12,19}));
    matrix.push_back(vector<int>({3,6,9,16,22}));
    matrix.push_back(vector<int>({10,13,14,17,24}));
    matrix.push_back(vector<int>({18,21,23,26,30}));


    Solution solution;
    cout << solution.searchMatrix(matrix, 5) << endl;
    return 0;
}
