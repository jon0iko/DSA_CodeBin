#include<iostream>
using namespace std;

struct Tree{
    int data;
    Tree *left;
    Tree *right;
    Tree(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

bool sameTree(Tree* root1, Tree* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    else if(root1==NULL || root2==NULL)
    {
        return false;
    }
    else
    {
        bool cond1=root1->data==root2->data;
        bool cond2=sameTree(root1->left, root2->left);
        bool cond3=sameTree(root1->right, root2->right);
        if(cond1 && cond2 && cond3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    Tree* root1=new Tree(1);
    root1->left=new Tree(2);
    root1->right=new Tree(3);

    Tree* root2=new Tree(1);
    root2->left=new Tree(2);
   // root2->right=new Tree(3);

    if(sameTree(root1, root2))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    return 0;
}