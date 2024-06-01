//09
#include<iostream>
using namespace std;
struct node
{
    int val;
    node *left_child = NULL;
    node *right_child = NULL;
};
struct BT
{
    node *root = NULL;
    void add_root(int val)
    {
        node *new_node = new node();
        new_node->val = val;
        new_node->left_child = NULL;
        new_node->right_child = NULL;
        root = new_node;
    }
    bool add_child(int val1, int val2, node *p, bool *found,int op)
    {
        if (*found == true)
            return *found;
        if (p == NULL)
            return false;
        if (p->val == val1)
        {
            if (op==0)
            {
                node *temp = new node();
                temp->val = val2;
                temp->left_child = NULL;
                temp->right_child = NULL;
                p->left_child = temp;
                *found = true;
                return *found;
            }
            else if (op==1)
            {
                node *temp = new node();
                temp->val = val2;
                temp->left_child = NULL;
                temp->right_child = NULL;
                p->right_child = temp;
                *found = true;
                return *found;
            }
            else return *found;
        }
        else
        {
            add_child(val1, val2, p->left_child, found,op);
            add_child(val1, val2, p->right_child, found,op);
            return *found;
        }
    }
    void In_Order_Traversal(node *p,node *q,bool *flag)
    {
        if(*flag==false)return;
        if ((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL)){
            ///cout<<"tt"<<endl;
            *flag=false;
            return;
        }
        else if(p==NULL&&q==NULL)return;    
        In_Order_Traversal(p->left_child,q->left_child,flag);
        if(p->val!=q->val){
            //cout<<p->val<<" "<<q->val<<endl;
            *flag=false;
            return;
        }
        In_Order_Traversal(p->right_child,q->right_child,flag);
    }
};
int main()
{
    BT *new_BT = new BT();
    int root;
    cin>>root;
    node* new_node=new node();
    new_node->val=root;
    new_node->left_child=NULL;
    new_node->right_child=NULL;
    new_BT->root=new_node;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int op, parent_val, child_val;
        cin >>op>> parent_val >> child_val;
        bool flag=false;
        if (!new_BT->add_child(parent_val, child_val, new_BT->root, &flag,op))
        {
            
        }
    }
    BT *new_BT2 = new BT();
    int root2;
    cin>>root2;
    node* new_node2=new node();
    new_node2->val=root2;
    new_node2->left_child=NULL;
    new_node2->right_child=NULL;
    new_BT2->root=new_node2;
    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        int op, parent_val, child_val;
        cin >>op>> parent_val >> child_val;
        bool flag=false;
        if (!new_BT2->add_child(parent_val, child_val, new_BT2->root, &flag,op))
        {
            
        }
    }
    bool flag=true;
    new_BT->In_Order_Traversal(new_BT->root,new_BT2->root,&flag);
    if(flag){
        cout<<"1"<<endl;
    }
    else cout<<"0"<<endl;
}