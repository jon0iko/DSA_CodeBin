//implement queue using linked list
#include <iostream>
using namespace std;

struct Queue
{

    struct node
    {
        node *next;
        int val;
    };
    node *head = NULL;
    node *tail = NULL;

    void enqueue(int x)
    {

        // Your code starts here #001
        node *a = (node *)malloc(sizeof(node));
        a->val = x;
        a->next = NULL;
        if (head == NULL)
        {
            head = tail = a;
            return;
        }
        tail->next = a;
        tail = a;

        // Your code ends here #001
    }

    int dequeue()
    {

        // Your code starts here #002
        if (head == NULL)
        {
            return -1;
        }
        int x = head->val;
        head = head->next; 
        return x;

        // Your code ends here #002
    }
};

int main()
{
    // Your code starts here #003
    int n, v, y;
    Queue q;
    cin >> n;
    y = n;
    while (n--)
    {
        cin >> v;
        q.enqueue(v);
        cout << q.dequeue() << endl;
    }
    
    
    // Your code ends here #003
    return 0;
}