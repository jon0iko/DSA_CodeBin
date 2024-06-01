#include <bits/stdc++.h>
using namespace std;
#define n 100

struct aQueue
{
    int arr[n];
    int front;
    int back;

    void push(int x)
    {
        if (back == n - 1)
        {
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
    }

    void pop() {
        if (front==-1 || front>back)
        {
            return;
        }
        front++;
    }

    int peek() {
        if (front==-1 || front>back)
        {
            return -1;
        }
        return arr[front];
    }

    bool empty() {
        if (front==-1 || front>back)
        {
            return true;
        }
        return false;
    }
};

struct lQueue
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

struct circularQueue
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

class CircularQueue {
    int *arr;           // Array to store queue elements
    int front, rear;    // Front and rear pointers
    int capacity;       // Maximum capacity of the queue
    int size;           // Current size of the queue

    public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Function to enqueue an element
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        if (front == -1)    // If the queue was initially empty
            front = rear;
        size++;
        cout << item << " enqueued to the queue\n";
    }

    // Function to dequeue an element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int item = arr[front];
        if (front == rear)  // If there was only one element in the queue
            front = rear = -1;
        else
            front = (front + 1) % capacity;
        size--;
        return item;
    }

    // Function to get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        // int i = front;
        // do {
        //     cout << arr[i] << " ";
        //     i = (i + 1) % capacity;
        // } while (i != (rear + 1) % capacity);

        for (int i = front; i != rear; i = (i + 1) % capacity) {
            cout << arr[i] << " ";
        }


        // for (int i = 0; i < size; i++) {
        //     cout << arr[i] << " ";
        // }
        cout << endl;
    }
};


int main()
{
    CircularQueue q = CircularQueue(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout << q.dequeue() << " dequeued from the queue\n";

    q.enqueue(60);
    
    q.display();
    return 0;
}