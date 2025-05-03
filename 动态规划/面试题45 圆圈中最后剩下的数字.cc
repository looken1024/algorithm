/*
要求：0到n-1排成一圈，从0开始每次数m个数删除，求最后剩余的数
思路：当 n > 1 时： f(n,m) = [f(n-1, m)+m]%n,当 n = 1 时： f(n,m)=0，关键是推导出关系表达式
*/

#include <iostream>

using namespace std;

int last_num(int n, int m) {
    if (n == 1) {
        return 0;
    }
    int num = 0;
    for (int i = 2; i <= n; i++) {
        num = (num + m) % i;
    }
    return num;

}

int main() {
    cout << last_num(5, 3) << endl;
    return 0;
}
