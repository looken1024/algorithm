#include <iostream>

using namespace std;

int countof1(int num) {
    int count = 0;
    while (num != 0) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }
    return count;
}

int main() {
    cout << countof1(-256) << endl;
    return 0;
}
