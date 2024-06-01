//insert at first or last of a linked list
#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};

node *head = NULL;
node *tail = NULL;

void insert_first(int x)
{
    node *a = (node *)malloc(sizeof(node));
    a->val = x;
    a->next = NULL;
    if (head == NULL)
    {
        head = a;
        tail = a;
    }
    else
    {
        a->next = head;
        head = a;
    }
}

void insert_last(int x)
{
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
}

void print()
{
    node *p = head;
    while (p)
    {
        cout << p->val<< endl;
        p = p->next;
    }
}

int main()
{
    int n, p, v;
    cin >> n;
    while (n--)
    {
        cin >> p >> v;
        switch (p)
        {
        case 0:
            insert_first(v);
            break;
        case 1:
            insert_last(v);
            break;
        default:
            break;
        }
    }
    print();

    return 0;
}