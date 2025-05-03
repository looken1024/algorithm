#include <iostream>
#include <vector>

using namespace std;

vector<int> fibonacci(int len) {
    vector<int> s({0, 1});
    for (int i = 2; i <= len; i++) {
        s.push_back(s[i - 1] + s[i - 2]);
    }
    return s;
}

int main() {
    vector<int> s = fibonacci(10);
    for (auto it : s) {
        cout << it << endl;
    }
}
