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


bool isEmpty()
    { // to check if the stack is empty
        return head == NULL;
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

struct Queue {
    StackII s1,s2;
    void enq(int x){
        s1.push(x);
    }

    int deq(){
        if(s1.head==NULL && s2.head==NULL) return -1;
        if(s2.head==NULL){
            while(s1.head!=NULL){
               // int val=s1.pop();
                s2.push(s1.peek());
                s1.pop();
            }
        }
        int topval=s2.peek();
        s2.pop();
        return topval;
    }

    bool empty(){
        if(s1.isEmpty() && s2.isEmpty())
         return true;
        else return false; 
    }
};



int main() {
    Queue q;

    // Enqueue elements
    q.enq(1);
    q.enq(2);
    q.enq(3);

    // Dequeue and print elements
    cout << q.deq() << endl; // Output: 1
    cout << q.deq() << endl; // Output: 2

    // Enqueue more elements
    q.enq(4);
    //q.enq(5);

   
    // Dequeue and print remaining elements
    //while(!q.empty()) {
        cout << q.deq() << " "; // Output: 3 4 5
    //}
    cout << endl;

    return 0;
}