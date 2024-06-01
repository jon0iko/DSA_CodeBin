#include<iostream>
using namespace std;

#define INT_MAX 1000000

struct MaxHeap{
    int *arr;
    int size;
    int capacity;
    MaxHeap(int c){
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    int left(int i){
        return (2*i + 1);
    }

    int right(int i){
        return (2*i + 2);
    }

    int parent(int i){
        return (i-1)/2;
    }

    void insert(int x){
        if(size == capacity) return;
        size++;
        arr[size-1] = x;
        for(int i=size-1; i!=0 && arr[parent(i)] < arr[i];){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i){
        int lt = left(i);
        int rt = right(i);
        int largest = i;
        if(lt < size && arr[lt] > arr[largest]) largest = lt;
        if(rt < size && arr[rt] > arr[largest]) largest = rt;
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    int extractMax(){
        if(size == 0) return -1;
        if(size == 1){
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size-1]);
        size--;
        heapify(0);
        return arr[size];
    }

    void decreaseKey(int i, int x){
        arr[i] = x;
        while(i != 0 && arr[parent(i)] < arr[i]){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i){
        decreaseKey(i, INT_MAX);
        extractMax();
    }
};

int main(){
    MaxHeap h(10);
    h.insert(10);
    h.insert(5);
    h.insert(20);
    cout << h.extractMax() << endl;
    cout << h.extractMax() << endl;
    h.insert(5);
    h.insert(20);
    h.decreaseKey(1, 1);
    cout << h.extractMax() << endl;
    h.deleteKey(5);
    return 0;
}