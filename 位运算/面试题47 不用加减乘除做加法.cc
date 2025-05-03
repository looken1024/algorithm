/*
要求：不用加减乘除做加法

方法思路
无进位和：使用异或运算（^）计算两个数的不考虑进位的和。
进位：使用与运算（&）和左移运算（<<）计算进位，进位需要左移一位以作用于高位。
循环处理：将无进位和与进位重复上述步骤，直到进位为零，此时的无进位和即为最终结果。
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            int sum = a ^ b;               // 计算无进位和
            unsigned int carry = (unsigned int)(a & b) << 1; // 计算进位并转换为无符号避免溢出
            a = sum;
            b = (int)carry;
        }
        return a;
    }
};

int main() {
    int a = 2131;
    int b = 983;
    Solution solution;
    cout << solution.add(a, b) << endl;
    return 0;
}
