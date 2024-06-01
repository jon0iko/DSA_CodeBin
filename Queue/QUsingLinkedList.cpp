#include<iostream>
using namespace std;

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

    void dequeue(){
        if(front==NULL){
            return;
        }

        front=front->next;
    }

    int peek(){
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

    void print(){
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


int main(){
    Queue q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.enqueue(x);
    }
    q.print();
    cout<< q.peek()<<endl;
    q.print();
    q.dequeue();
   // q.peek();
    cout<< q.peek()<<endl;
    q.enqueue(10);
    q.dequeue();
    q.print();
    return 0;
}
