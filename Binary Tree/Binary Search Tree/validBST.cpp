#include<iostream>
using namespace std;

struct BST
{
    int data;
    BST *left;
    BST *right;

    BST(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

bool isBST(BST* root, BST* min=NULL, BST* max=NULL)
{
    if(root==NULL)
    {
        return true;
    }
    if(min!=NULL && root->data<=min->data)
    {
        return false;
    }
    if(max!=NULL && root->data>=max->data)
    {
        return false;
    }
    bool leftValid=isBST(root->left, min, root);
    bool rightValid=isBST(root->right, root, max);
    return leftValid && rightValid;
}

int main()
{
    BST* root=new BST(2);
    root->left=new BST(1);
    root->right=new BST(3);
    root->right->right=new BST(-1);
    if(isBST(root, NULL, NULL))
    {
        cout<<"Valid BST"<<endl;
    }
    else
    {
        cout<<"Invalid BST"<<endl;
    }
    return 0;
}