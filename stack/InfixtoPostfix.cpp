#include <iostream>
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

int precedence (char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='/' || c=='*'){
        return 2;
    }
    else if(c=='+' ||c=='-'){
        return 1;
    }
    else return 0;
}

bool isOperand(char c){
    if((c>='a' && c<='z')|| (c>='A' && c<='Z')||(c>='0' && c<='9')){
        return true;
    }
    return false;
}

string infixToPostfix(string s,StackII &st){
    string postfix;
    for(int i=0;i<s.size();i++){
        if(isOperand(s[i])){
            postfix+=s[i];
        }
        else if(s[i]=='('){
            st.push('(');
        }
        else if(s[i]==')'){
            while(st.peek()!='('){
                postfix+=st.peek();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.isEmpty() && precedence(s[i])<=precedence(st.peek())){
                postfix+=st.peek();
                st.pop();
            }
            st.push(s[i]); 
        }
    }
    while(!st.isEmpty()){
        postfix+=st.peek();
        st.pop();
    }
    return postfix;
}

int main(){
    string inf;
    cin>>inf;
    StackII s;
    cout<<infixToPostfix(inf,s);
}