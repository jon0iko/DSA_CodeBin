#include<iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if(root == NULL) return NULL;
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}
//bujhe korsi
 TreeNode* InvertTree(TreeNode* root) {
        // Base Case
        if(root==NULL)
            return NULL;
        invertTree(root->left); //Call the left substree
        invertTree(root->right); //Call the right substree
        // Swap the nodes
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root; // Return the root
 }


void postorder(TreeNode* root){
        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }

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
    // TreeNode* root = new TreeNode(4);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(7);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(9);
    // TreeNode* newRoot = InvertTree(root);
    // cout << newRoot->val << endl;
    // cout << newRoot->left->val << endl;
    // cout << newRoot->right->val << endl;
    // cout << newRoot->left->left->val << endl;
    // cout << newRoot->left->right->val << endl;
    // cout << newRoot->right->left->val << endl;
    // cout << newRoot->right->right->val << endl;
    // postorder(newRoot);
    //incase of taking input from user
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    TreeNode* root = insertLevelOrder(arr, root, 0, n);
    TreeNode* newRoot = invertTree(root);
    levelOrderTraversal(newRoot);
    
    return 0;
}