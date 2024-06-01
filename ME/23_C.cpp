#include<bits/stdc++.h>
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

    int printMin() {
        if (size <= 0) {
            return -1;
        }
        int min = arr[0];
        cout<< min<<endl;
    }

    void deleteElement(int x) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == x) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Element not found in the heap" << endl;
        return;
    }
    arr[index] = arr[size - 1];
    size--;
    heapifyDown(index);
    }

};


int main()
{
    Heap heap(10000);
    int q,x;
    cin >> q;
    while (q--)
    {
        cin >> x;
        if(x==1) {
            cin>>x;
            heap.insert(x);
        }
        else if(x==2) {
            cin>>x;
            heap.deleteElement(x);
        }
        else if(x==3) {
            heap.printMin();
        }
    }
    
    
    return 0;
}