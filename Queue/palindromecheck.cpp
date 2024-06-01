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

 int pop(){
    if(head==NULL) return -1;
    head=head->next;
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

struct Queue
{
    struct node {
        int val;
        node* next;
    };
    node* front=NULL;
    node* rear=NULL;

    void enqueue(int x){
       node* a=(node*)malloc(sizeof(node));
       a->val=x;
       a->next=NULL;
       if(front==NULL){
        front=rear=a;
        return;
       }
       rear->next=a;
       rear=a;
    }

    int dequeue(){
        if(front==NULL){
            return -1;
        }

        front=front->next;
    }

    int peekQ(){
        if(front==NULL){
            return -1;
        }
        return front->val;
    }

    bool empty(){
        if(front==NULL){
            return true;
        }
        return false;
    }

    void printQ(){
        if(front==NULL){
            cout<< "Queue is empty.\n";
            return;
        } 
        node* p=front;
        while(p){
            cout<<p->val<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};

void ispalindrome(string s)
{
    int n=s.length();
    StackII last;
    Queue first;
    for(int i=0;i<(n/2);i++)
    {
        first.enqueue(s[i]);
    }
    if(n%2==0)
    {
       for(int i=(n/2);i<n;i++)
        {
            last.push(s[i]);
        }
    }
    else
    {
            for(int i=(n+1)/2;i<n;i++)
            {
               last.push(s[i]);
            }
    }
    for(int i=0;i<n/2;i++){
        if(first.peekQ()!=last.peek()){
            cout<< "Not palindrome"<<endl;
            return;
        }
        else
        {
          first.dequeue();
          last.pop();
        }
    }
          cout<<"Palindrome"<<endl;
          return;
    
  
}


int main()
{
      
       string s;
       cin>>s;
      
        
        ispalindrome(s);
        
        




}
