/*
要求：用两个栈实现队列，分别实现入队和出队操作 思路：一个栈负责入队，另一个负责出队，出栈为空则从入栈中导入到出栈中
*/

#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    void push(int v) {
        s1.push(v);
    }

    int pop() {
        while (!s1.empty()) {
            int v = s1.top();
            s1.pop();
            s2.push(v);
        }
        int v = s2.top();
        s2.pop();
        while (!s2.empty()) {
            int v = s2.top();
            s2.pop();
            s1.push(v);
        }
        return v;
    }

private:
    stack<int> s1;
    stack<int> s2;
};

int main() {
    Queue q;
    for (int i = 10; i < 100; i++) {
        q.push(i);
    }
    cout << q.pop() << endl;
    return 0;
}

