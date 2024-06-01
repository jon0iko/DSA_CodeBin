//delete in a range in linked list
#include <iostream>
using namespace std;

struct ll
{

    struct node
    {
        node *next;
        int val;
    };
    node *head = NULL;
    node *tail = NULL;

    void insert_last(int x)
    {
        // insert x at last

        // Your code starts here #001
        node *a = (node *)malloc(sizeof(node));
        a->val = x;
        a->next = NULL;
        if (tail)
        {
            tail->next = a;
            tail = a;
        }
        else
        {
            head = a;
            tail = a;
        }

        // Your code ends here #001
    }

    void delete_range(int l, int u)
    {
        // deletes values within the range l and u, inclusive

        // Your code starts here #002
        node *now = head;
        while (now->next != NULL)
        {
            if(now->next->val >=l && now->next->val <= u){
                    now->next = now->next->next;
            }
            else now = now->next;
        }

        if(head->val >= l && head->val <= u){
            head = NULL;
        }
        // Your code ends here #002
    }

    void print()
    {
        // prints elements from head to tail

        // Your code starts here #003
        node *p = head;
        while (p)
        {
            cout << p->val << endl;
            p = p->next;
        }
        // Your code ends here #003
    }
};

int main()
{

    // Your code starts here #004
    int n, v;
    ll st;
    cin >> n;
    if(n==0) return 0;
    while (n--)
    {
        cin >> v;
        st.insert_last(v);
    }
    int l, u;
    cin >> l >> u;
    st.delete_range(l, u);
    st.print();
    // Your code ends here #004
    return 0;
}