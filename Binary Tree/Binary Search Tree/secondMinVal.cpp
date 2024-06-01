#include <bits/stdc++.h>
using namespace std;
 
// Structure of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 

vector<int> ans;
 

void inorderTraversal(Node* root)
{
    if (root != NULL) {
        inorderTraversal(root->left);
        ans.push_back(root->data);
        inorderTraversal(root->right);
    }
}
 

int findSecondMinimumValue(Node* root)
{
    inorderTraversal(root);
 
    
    sort(ans.begin(), ans.end());
 

    for (int i = 0; i < ans.size() - 1; i++)
        if (ans[i] != ans[i + 1])
            return ans[i + 1];
    return -1;
}

int FindSecondMinimumValue(Node* root)
{
    
    if (!root)
        return -1;
 
   
    
    if (!root->left && !root->right)
        return -1;
 
    auto left = root->left->data;
 
    auto right = root->right->data;
 
   
    if (root->data == root->left->data)
        left
            = findSecondMinimumValue(root->left);
 
    
    if (root->data == root->right->data)
        right
            = findSecondMinimumValue(root->right);
 
    if (left != -1 && right != -1)
        return min(left, right);
 
    else if (left != -1)
        return left;
 
   
    else
        return right;
}
 
int main()
{
    
    struct Node* root = new Node(2);
    root->left = new Node(2);
    root->right = new Node(5);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
 
    
    int SecondMinimumValue
        = findSecondMinimumValue(root);
    cout << SecondMinimumValue << endl;
    return 0;
}