#include <iostream>
#include <stack>

using namespace std;

struct Node {
    Node(int val_) {
        val = val_;
        left = nullptr;
        right = nullptr;
    }

    int val;
    Node* left;
    Node* right;
};

int depth(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return 1 + max(depth(root->left), depth(root->right));
}

int depth2(Node* root) {
    stack<Node*> s;
    int max_depth = 0;
    int depth = 1;
    s.push(root);
    while (root->left != nullptr) {
        s.push(root->left);
        root = root->left;
        depth++;
        max_depth = max(depth, max_depth);
    }
    while (!s.empty()) {
        Node* t = s.top();
        s.pop();
        if (t->right != nullptr) {
            s.push(t->right);
            t = t->right;
            depth++;
            max_depth = max(depth, max_depth);
            while (t->left != nullptr) {
                s.push(t->left);
                t = t->left;
                depth++;
                max_depth = max(depth, max_depth);
            }
        } else {
            depth--;
        }
    }
    return max_depth;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(3);
    root->right->right->right = new Node(3);
    root->right->right->right->left = new Node(3);
    root->right->right->right->left->right = new Node(3);
    root->left->left = new Node(4);
    cout << depth(root);
    cout << depth2(root);
    return 0;
}

