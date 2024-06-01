#include<iostream>
using namespace std;

struct StackII {
    struct stack 
    {
        int val;
        stack* next;
    };
    stack* head=NULL;
    

 void push(int x){
    stack* node=(stack*)malloc(sizeof(stack));
    node->val=x;
    node->next=head;
    head=node;
 }

 void pop(){
    if(head==NULL) return;
    stack* temp=head;
    head=head->next;
    free(temp);
 }
 int peek(){
    return head->val;
 }

 void print(){
    stack* p=head;
    while(p){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
 }
    
};

int main(){
    StackII st;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        st.push(x);
    }
    cout<<"printing the top element of stack: "<<st.peek()<<endl;
    st.pop();
    st.pop();
    st.print();
    return 0;
}