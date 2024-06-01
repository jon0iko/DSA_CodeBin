#include <iostream>
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
        if (front == NULL) {
            front = rear = a;
            rear->next = front; // Circular link
        } else {
            rear->next = a;
            rear = a;
            rear->next = front; // Circular link
        }
    }

    void dequeue(){
        if(front == NULL){
            return;
        }
        if(front == rear) {
            free(front);
            front = rear = NULL;
        } else {
            node* temp = front;
            front = front->next;
            rear->next = front; // Update circular link
            free(temp);
        }
    }

    int peek(){
        if(front == NULL){
            return -1;
        }
        return front->val;
    }

    bool empty(){
        return front == NULL;
    }

    void print(){
        if(front == NULL){
            cout << "Queue is empty.\n";
            return;
        } 
        node* p = front;
        do {
            cout << p->val << " ";
            p = p->next;
        } while(p != front);
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print(); // Output: 1 2 3
    q.dequeue();
    q.print(); // Output: 2 3
    cout << "Front element: " << q.peek() << endl; // Output: 2
    return 0;
}
