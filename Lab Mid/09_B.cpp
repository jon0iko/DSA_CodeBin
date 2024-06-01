//09
//09
#include<iostream>
using namespace std;
struct node
{
    int val;
    node *left;
    node *mid;
    node *right;
};
struct Tree
{
    node *root = NULL;
    void add_node(node *p, int op, int parent, int child)
    {
        if (!p)
            return;
        if (p->val == parent)
        {
            node *new_node = new node();
            new_node->val = child;
            new_node->left=NULL;
            new_node->right=NULL;
            new_node->mid=NULL;
            if (op == 0)
            {
                p->left=new_node;
            }
            else if(op==1){
                p->mid=new_node;
            }
            else{
                p->right=new_node;
            }
            return;
        }
        add_node(p->left,op,parent,child);
        add_node(p->mid,op,parent,child);
        add_node(p->right,op,parent,child);
    }
    void print(node *p){
        if(!p)return;
        print(p->left);
        print(p->mid);
        cout<<p->val<<endl;
        print(p->right);
    }
}; 
int main()
{
    int root_val;
    cin>>root_val;
    Tree* new_tree=new Tree();
    node* new_node=new node();
    new_node->val=root_val;
    new_node->left=NULL;
    new_node->mid=NULL;
    new_node->right=NULL;
    new_tree->root=new_node;
    int n;
    cin>>n;
    while(n--){
        int op,parent,child;
        cin>>op>>parent>>child;
        new_tree->add_node(new_tree->root,op,parent,child);
    }
    new_tree->print(new_tree->root);
}