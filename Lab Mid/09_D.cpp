//09
#include <iostream>
using namespace std;

#define INT_MAX 2147483647

struct BST
{
    struct node
    {
        int val;
        node *left;
        node *right;
        node *parent;
    };
    node *root = NULL;

    void insert_value(node *p, int x)
    {
        // Your code starts here - 001
        if (root == NULL)
        {
            node *new_node = new node();
            new_node->val = x;
            new_node->left = NULL;
            new_node->right = NULL;
            new_node->parent = NULL;
            root = new_node;
            return;
        }
        if (x >= p->val && p->right == NULL)
        {
            node *new_node = new node();
            new_node->val = x;
            new_node->left = NULL;
            new_node->right = NULL;
            new_node->parent = NULL;
            p->right = new_node;
            p->right->parent = p;
            return;
        }
        else if (x < p->val && p->left == NULL)
        {
            node *new_node = new node();
            new_node->val = x;
            new_node->left = NULL;
            new_node->right = NULL;
            new_node->parent = NULL;
            p->left = new_node;
            p->left->parent = p;
            return;
        }
        else if (x >= p->val)
        {
            insert_value(p->right, x);
        }
        else
        {
            insert_value(p->left, x);
        }

        // Your code ends here - 001
    }

    void inorder(node *p)
    {
        // Your code starts here - 002
        if (!p)
            return;
        inorder(p->left);
        cout << p->val << endl;
        inorder(p->right);
        // Your code ends here - 002
    }

    void delete_value(int x)
    {
        // Your code starts here - 003
        node *head = root;
        if (!head)
            return;
        while(head&&head->val!=x){
            if(x>head->val)head=head->right;
            else head=head->left;
        }
        if(head==NULL)return;
        int child_count = 0;
        if (head->left != NULL)
            child_count++;
        if (head->right != NULL)
            child_count++;
        if (child_count == 0)
        {
            bool left_child = false;
            bool right_child = false;
            if (head->parent->left && head->parent->left->val == x)
                left_child = true;
            else
                right_child = true;
            if (left_child)
            {
                head->parent->left = NULL;
            }
            else
            {
                head->parent->right = NULL;
            }
            return;
        }
        else if (child_count == 1)
        {
            bool left_child = false;
            bool right_child = false;
            if (head->parent->left && head->parent->left->val == x)
                left_child = true;
            else
                right_child = true;
            bool right2 = false;
            bool left2 = false;
            if (head->left != NULL)
                left2 = true;
            else
                right2 = true;
            if (left_child)
            {
                if (right2)
                {
                    head->parent->left = head->right;
                }
                else
                {
                    head->parent->left = head->left;
                }
            }
            else
            {
                if (right2)
                {
                    head->parent->right = head->right;
                }
                else
                {
                    head->parent->right = head->left;
                }
            }
            return;
        }
        else if (child_count == 2)
        {
            node *temp = head->right;
            node *delete_node = temp;
            int mino = temp->val;
            while (temp->left)
            {
                delete_node = temp->left;
                temp = temp->left;
            }
            int child_count = 0;
            if (delete_node->right)
                child_count++;
            int temp2 = head->val;
            head->val = delete_node->val;
            delete_node->val = temp2;
            int val2 = delete_node->val;
            if (child_count == 0)
            {
                bool left_child = false;
                bool right_child = false;
                if (delete_node->parent->left && delete_node->parent->left->val == val2)
                    left_child = true;
                else
                    right_child = true;
                if (left_child)
                {
                    delete_node->parent->left = NULL;
                }
                else
                {
                    delete_node->parent->right = NULL;
                }
                return;
            }
            else
            {
                bool left_child = false;
                bool right_child = false;
                if (delete_node->parent->left && delete_node->parent->left->val == val2)
                    left_child = true;
                else
                    right_child = true;
                bool right2 = false;
                bool left2 = false;
                if (delete_node->left != NULL)
                    left2 = true;
                else
                    right2 = true;
                if (left_child)
                {
                    if (right2)
                    {
                        delete_node->parent->left = delete_node->right;
                    }
                    else
                    {
                        delete_node->parent->left = delete_node->left;
                    }
                }
                else
                {
                    if (right2)
                    {
                        delete_node->parent->right = delete_node->right;
                    }
                    else
                    {
                        delete_node->parent->right = delete_node->left;
                    }
                }
                return;
            }
        }

        // Your code ends here - 003
    }
};

int main()
{

    BST *bst = new BST();
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        bst->insert_value(bst->root, v);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int v;
        cin >> v;
        bst->delete_value(v);
    }
    bst->inorder(bst->root);
    return 0;
}
