#include<iostream>
using namespace std;

#define INT_MIN -1000000

struct MinHeap{
    int *arr;
    int size;
    int capacity;
    MinHeap(int c){
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
        for(int i=size-1; i!=0 && arr[parent(i)] > arr[i];){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i){
        int lt = left(i);
        int rt = right(i);
        int smallest = i;
        if(lt < size && arr[lt] < arr[smallest]) smallest = lt;
        if(rt < size && arr[rt] < arr[smallest]) smallest = rt;
        if(smallest != i){
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    int extractMin(){
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
        while(i != 0 && arr[parent(i)] > arr[i]){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i){
        decreaseKey(i, INT_MIN);
        extractMin();
    }
};

int main(){
    MinHeap h(10);
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(40);
    cout << h.extractMin() << endl;
    cout << h.arr[0] << endl;
    h.decreaseKey(2, 5);
    cout << h.arr[0] << endl;
    h.deleteKey(0);
    cout << h.arr[0] << endl;
    return 0;
}
