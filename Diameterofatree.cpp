#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(Node* root, int& ans) {
    if (root == NULL) {
        return 0;
    }
    int left_height = height(root->left, ans);
    int right_height = height(root->right, ans);
    ans = max(ans, 1 + left_height + right_height);
    return max(left_height, right_height);
}

int main () {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    
    root->left->left = newNode(4);
    root->right->right = newNode(5);
    root->left->right = newNode(6);
    root->right->left = newNode(7);

    root->left->left->left = newNode(8);

    int ans_l = 0, ans_r = 0;
    height(root -> left, ans_l);
    height(root -> right, ans_r);
    cout << ans_l + ans_r << endl;
    return 0;
}