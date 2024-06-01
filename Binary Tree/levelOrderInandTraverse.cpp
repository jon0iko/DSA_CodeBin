#include <iostream>
#include <queue> // For level order traversal

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert nodes into the binary tree level by level
TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n) {
    // Base case for recursion
    if (i < n) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;

        // Insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // Insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// Function to perform level order traversal of binary tree
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL)
        return;

    // Create a queue for level order traversal
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        cout << current->val << " ";
        q.pop();

        // Enqueue left child
        if (current->left != NULL)
            q.push(current->left);

        // Enqueue right child
        if (current->right != NULL)
            q.push(current->right);
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    TreeNode* root = insertLevelOrder(arr, root, 0, n);
    levelOrderTraversal(root);
    

    return 0;
}