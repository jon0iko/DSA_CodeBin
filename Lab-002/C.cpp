//sort a linked list
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

    void sort()
    {
        // Sorts the linked list
        node *temp=head;
        while(temp!=NULL){
            node* t2=head;
            while(t2!=NULL){
                if(t2->val>temp->val){
                    swap(t2->val,temp->val);
                }
                t2=t2->next;
            }
            temp=temp->next;
        }
        // Your code starts here #002
        
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
    ll st;
    int n, v;
    cin >> n;
    while (n--)
    {
        cin >> v;
        st.insert_last(v);
        st.sort();
    }
    st.print();
    // Your code ends here #004
    return 0;
}