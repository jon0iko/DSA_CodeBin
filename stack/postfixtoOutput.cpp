#include <iostream>
#include <cmath>
using namespace std;

struct StackII
{
    struct stack
    {
        int val;
        stack *next;
    };
    stack *head = NULL;

    void push(int x)
    {
        stack *node = (stack *)malloc(sizeof(stack));
        node->val = x;
        node->next = head;
        head = node;
    }

    void pop()
    {
        if (head == NULL)
            return;
        head = head->next;
    }
    int peek()
    {
        return head->val;
    }

    bool isEmpty()
    { // to check if the stack is empty
        return head == NULL;
    }
    void print()
    {
        stack *p = head;
        while (p)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int evaluatePostfix(string p, StackII &s)
{
    for (int i = 0; i < p.size(); i++)
    {
        if (isdigit(p[i]))
        { // operands
            s.push(p[i] - '0');
        }
        else
        { // operator
            int val1 = s.peek();
            s.pop();
            int val2 = s.peek();
            s.pop();
            switch (p[i])
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val2 - val1);
                break;
            case '*':
                s.push(val2 * val1);
                break;
            case '/':
                s.push(val2 / val1);
                break;
            case '^':
                s.push(pow(val2, val1));
                break;
            }
        }
    }
    return s.peek();
}

int main()
{
    string postfix;
    cin >> postfix;
    StackII s;
    cout << evaluatePostfix(postfix, s) << endl;
    return 0;
}