#include<iostream>
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


bool isValid(string s){
    int n=s.size();
    StackII st;
    bool answer=true;
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
       }
       else if(s[i]==')'){
              if(!st.isEmpty() && st.peek()=='('){
                st.pop();
              }
              else {
                answer=false;
                break;
              }
       }
       else if(s[i]=='}'){
              if(!st.isEmpty() && st.peek()=='{'){
                st.pop();
              }
              else {
                answer=false;
                break;
              }
       }
       else if(s[i]==']'){
              if(!st.isEmpty() && st.peek()=='['){
                st.pop();
              }
              else {
                answer=false;
                break;
              }
       }
}
if(!st.isEmpty()){
    return false;
}
 return answer;
    
}

int main()
{
    string s;
    cin>>s;
    if(isValid(s)){
        cout<<"True"<<endl;
    }
    else cout<<"False"<<endl;
    return 0;
}