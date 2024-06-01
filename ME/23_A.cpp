#include <bits/stdc++.h>
using namespace std;

class Heap {
    int* arr;
    int capacity;
    int size;

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[index] < arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && arr[left] < arr[smallest]) {
                smallest = left;
            }

            if (right < size && arr[right] < arr[smallest]) {
                smallest = right;
            }

            if (smallest != index) {
                swap(arr[index], arr[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    Heap(int capacity) : capacity(capacity), size(0) {
        arr = new int[capacity];
    }

    void insert(int value) {
        if (size >= capacity) {
            cout << "Heap is full" << endl;
            return;
        }
        arr[size] = value;
        heapifyUp(size);
        size++;
    }

    void remove() {
        if (size <= 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
    }

    void heapSort() {
        int* sorted = new int[size];
        int originalSize = size;
        for (int i = 0; i < originalSize; ++i) {
            sorted[i] = arr[0];
            remove();
        }
        for (int i = 0; i < originalSize; ++i) {
            insert(sorted[i]);
        }
        delete[] sorted;
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            if (i == 0)
            {
                cout << "[" << arr[i] <<",";
            }
            else if (i == size-1)
            {
                cout << arr[i] << "]";
            }
            else {
                cout <<arr[i]<<",";
            }

        }
    }
};

int main() {
    Heap heap(1000);

    int n,x;
    cin>>n;
    while (n--)
    {
        cin>>x;
        heap.insert(x);
    }

    heap.heapSort();
    heap.display();

    return 0;
}
