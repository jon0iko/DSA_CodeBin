

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}
bool isBalanced(TreeNode *root)
{
    int lh, rh;
    if (root == NULL)
        return 1;
    lh = height(root->left);
    rh = height(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    // isBalanced(root);
    if (isBalanced(root))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}