/*
给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。
按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

示例 1：
输入：n = 3, k = 3
输出："213"

示例 2：
输入：n = 4, k = 9
输出："2314"

示例 3：
输入：n = 3, k = 1
输出："123"

提示：
1 <= n <= 9
1 <= k <= n!
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> arr;
        for (int i = 1; i <= n; i++) {
            arr.push_back('0' + i);
        }
        return f("", arr, k);
    }

    string f(string pre, vector<char>& arr, int k) {
        // 添加终止条件
        if (arr.empty()) {
            return pre;
        }
        int n = arr.size();
        int fact = factorial(n - 1);  // (n-1)!
        // 找到应该选择的字符索引
        int index = (k - 1) / fact;  // 注意：k从1开始，所以要减1
        // 选择字符
        char chosen = arr[index];
        // 构建新的数组（移除已选择的字符）
        vector<char> new_arr;
        for (int i = 0; i < arr.size(); i++) {
            if (i != index) {
                new_arr.push_back(arr[i]);
            }
        }
        // 计算新的k
        int new_k = k - index * fact;
        // 递归调用
        return f(pre + chosen, new_arr, new_k);
    }

    int factorial(int n) {
        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }
};
