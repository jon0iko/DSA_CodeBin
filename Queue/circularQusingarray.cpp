#include <iostream>
using namespace std;

class CircularQueue {

    int *arr;           // Array to store queue elements
    int front, rear;    // Front and rear pointers
    int capacity;       // Maximum capacity of the queue
    int size;           // Current size of the queue


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
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        cout << endl;
    }
};

int main() {
    CircularQueue q(5); // Create a queue with capacity 5

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    q.enqueue(6);
    q.enqueue(7);

    cout << "Front element: " << q.peek() << endl;

    q.display();

    return 0;
}
