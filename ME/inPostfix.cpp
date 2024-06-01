#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100

struct Stack
{
    char data[MAX_SIZE];
    int top = -1;

    void push(char x)
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        data[++top] = x;
    }
    char pop()
    {
        if (top == -1)
        {
            cout << "empty stack" << endl;
            exit(2);
        }
        char ans = data[top];
        top--;
        return ans;
    }
    char peek()
    {
        if (top == -1)
        {
            cout << "empty" << endl;
            exit(2);
        }
        return data[top];
    }
    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%c ", data[i]);
        }
    }

    int empty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
}

bool isOperand(char c)
{
    if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')))
    {
        return true;
    }
    return false;
}

int main()
{
    Stack s;
    string infix, postfix;

    cin >> infix;

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if (isOperand(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (s.peek() != '(')
            {
                postfix += s.peek();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && (precedence(c) <= precedence(s.peek())))
            {
                postfix += s.peek();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        postfix += s.peek();
        s.pop();
    }

    cout << postfix << endl;
    return 0;
}