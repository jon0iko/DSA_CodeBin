#include <bits/stdc++.h>
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
    node *now = new node();
    now->val = x;
    now->next = NULL;

    if (head == NULL)
    {
        head = now;
        tail = now;
    }
    else
    {
        now->next = head;
        head = now;
    }
}

void insert_last(int x)
{
    node *now = (node *)malloc(sizeof(node));
    now->val = x;
    now->next = NULL;

    if (tail)
    {
        tail->next = now;
        tail = now;
    }
    else
    {
        head = now;
        tail = now;
    }
}

void printList()
{
    node *n = head;
    while (n)
    {
        cout << n->val << " ";
        n = n->next;
    }
}

int deleteFirst()
{
    if (head == NULL)
    {
        return -1;
    }
    if (head == tail)
    {
        int x = head->val;
        free(head);
        head = NULL;
        tail = NULL;
        return x;
    }
    else
    {
        int x = head->val;
        node *temp = head;
        head = head->next;
        free(temp);
        return x;
    }
}

int deleteLast()
{
    if (head == NULL)
    {
        return -1;
    }
    if (head == tail)
    {
        int x = head->val;
        free(head);
        head = NULL;
        tail = NULL;
        return x;
    }
    else
    {
        int x = tail->val;
        node *n = head;
        while (n->next->next != NULL)
        {
            n = n->next;
        }
        n->next = NULL;
        free(tail);
        tail = n;
        return x;
    }
}


struct doublyNode
{
    int val;
    doublyNode *next;
    doublyNode *prev;
};

doublyNode *headD = NULL;
doublyNode *tailD = NULL;

void insertFD(int x)
{
    doublyNode *now = (doublyNode *)malloc(sizeof(node));
    now->val = x;
    now->prev = NULL;
    now->next = NULL;

    if (head == NULL)
    {
        headD = now;
        tailD = now;
    }
    else
    {
        now->next = headD;
        headD->prev = now;
        headD = headD->prev;
    }
}

void insertLD(int x)
{
    doublyNode *now = (doublyNode *)malloc(sizeof(node));
    now->val = x;
    now->prev = NULL;
    now->next = NULL;

    if (head == NULL)
    {
        headD = now;
        tailD = now;
    }
    else
    {
        now->prev = tailD;
        tailD->next = now;
        tailD = tailD->next;
    }
}

struct CircularlinkedList

{
    struct CircularNode
    {
        int val;
        CircularNode *next;
    };

    CircularNode *hed = NULL;
    CircularNode *tel = NULL;

    void insertLC(int x)
    {
        CircularNode *now = new CircularNode();
        now->val = x;
        now->next = NULL;

        if (hed == NULL)
        {
            hed = now;
            tel = now;
            tel->next = hed;
        }
        else
        {
            now->next = tel->next;
            tel->next = now;
            tel = now;
        }
    }

    void insertFC(int x)
    {
        CircularNode *now = new CircularNode();
        now->val = x;
        now->next = NULL;

        if (hed == NULL)
        {
            hed = now;
            tel = now;
            tel->next = hed;
        }
        else
        {
            now->next = hed;
            tel->next = now;
            hed = now;
        }
    }

    int deleteLC()
    {
        if (hed == NULL)
        {
            return -1;
        }
        else if (hed == tel)
        {
            free(hed);
            hed == NULL;
            tel == NULL;
        }
        else
        {
            CircularNode *temp = hed;
            while (temp->next != tel)
            {
                temp = temp->next;
            }
            temp->next = tel->next;
            free(tel);
            tel = temp;
        }
    }

    int deleteFC()
    {
        if (hed == NULL)
        {
            return -1;
        }
        else if (hed == tel)
        {
            free(hed);
            hed == NULL;
            tel == NULL;
        }
        else
        {
            CircularNode *temp = hed;
            hed = hed->next;
            free(temp);
            tel->next = hed;
        }
    }

    void printC()
    {
        CircularNode *temp = hed;

        do
        {
            printf("%d ", temp->val);
            temp = temp->next;
        } while (temp!=hed);
        printf("\n");
    }
};

int main()
{
    int n, x;
    CircularlinkedList ll;
    cin >> n;
    while (n--)
    {
        cin>>x;
        ll.insertLC(x);
    }
    ll.printC();
    return 0;
}