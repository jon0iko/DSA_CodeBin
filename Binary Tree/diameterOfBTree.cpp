#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root, int& ans) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left, ans);
    int rightHeight = height(root->right, ans);
    ans = max(ans, 1 + leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    height(root, ans);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << diameterOfBinaryTree(root) << endl;
    return 0;
}