/*
颠倒给定的 32 位有符号整数的二进制位。

示例 1：
输入：n = 43261596
输出：964176192
解释：
整数      	二进制
43261596  	00000010100101000001111010011100
964176192 	00111001011110000010100101000000

示例 2：
输入：n = 2147483644
输出：1073741822
解释：
整数       	二进制
2147483644 	01111111111111111111111111111100
1073741822 	00111111111111111111111111111110

提示：
0 <= n <= 231 - 2
n 为偶数

进阶: 如果多次调用这个函数，你将如何优化你的算法？
*/

class Solution {
public:
    int reverseBits(int n) {
        uint32_t l = 1 << 31;
        uint32_t r = 1;
        bool l2;
        bool r2;
        int cnt = 0;
        while (cnt < 16) {
            l2 = (n & l) != 0;
            r2 = (n & r) != 0;
            if (l2) {
                n = n | r;
            } else {
                n = n & ~r;
            }
            if (r2) {
                n = n | l;
            } else {
                n = n & ~l;
            }
            l = l >> 1;
            r = r << 1;
            cnt++;
        }
        return n;
    }
};

class Solution {
public:
    int reverseBits(int n) {
        unsigned int num = n;
        unsigned int result = 0;
        for (int i = 0; i < 32; i++) {
            result = (result << 1) | (num & 1);
            num >>= 1;
        }
        return (int)result;
    }
};
