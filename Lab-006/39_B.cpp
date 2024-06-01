#include<iostream>
using namespace std;

struct Heap {
    int arr[1000000];
    int size = 0;

    void insert_min(int v) {
        arr[size] = v;
        size++;

        int current = size - 1;
        while (current > 0 && arr[current] < arr[(current - 1) / 2]) {
            int temp = arr[current];
            arr[current] = arr[(current - 1) / 2];
            arr[(current - 1) / 2] = temp;

            current = (current - 1) / 2;
        }
    }

    int extract_min() {
        int ret = arr[0];
        arr[0] = arr[size - 1];
        size--;

        int current = 0;
        while (true) {
            int left = current * 2 + 1;
            int right = current * 2 + 2;
            int smallest = current;

            if (left < size && arr[left] < arr[smallest]) smallest = left;
            if (right < size && arr[right] < arr[smallest]) smallest = right;

            if (smallest != current) {
                int temp = arr[smallest];
                arr[smallest] = arr[current];
                arr[current] = temp;
                current = smallest;
            } else {
                break;
            }
        }
        return ret;
    }
};

int main() {
    Heap *heap = new Heap();
    int n,k;
    cin >> n>>k;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        heap->insert_min(v);
    }

   
    int op=0;
    while (heap->size > 1 && heap->arr[0] < k) {
        int least_sweet = heap->extract_min();
        int second_least_sweet = heap->extract_min();
        int mixture =least_sweet  + 2 * second_least_sweet;
        
        heap->insert_min(mixture);
        op++;
    }
    if(heap->size==1 && heap->arr[0] < k)
        cout << -1 << endl;
    else
        cout << op << endl;
    return 0;
}
