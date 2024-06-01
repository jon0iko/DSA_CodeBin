#include <iostream>
#include <vector>

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

    ~Heap() {
        delete[] arr;
    }

    void insert(int value) {
        if (size >= capacity) {
            std::cout << "Heap is full" << std::endl;
            return;
        }
        arr[size] = value;
        heapifyUp(size);
        size++;
    }

    int remove() {
        if (size <= 0) {
            std::cout << "Heap is empty" << std::endl;
            return -1;
        }
        int removed = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
        return removed;
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int cookies(int k, std::vector<int>& A) {
    Heap heap(A.size());
    for (int i = 0; i < A.size(); ++i) {
        heap.insert(A[i]);
    }
    int operations = 0;
    while (!heap.isEmpty()) {
        int least_sweet = heap.remove();
        if (least_sweet >= k) {
            return operations;
        }
        if (heap.isEmpty()) {
            return -1; // Not possible to achieve sweetness >= k
        }
        int second_least_sweet = heap.remove();
        int new_cookie = least_sweet + 2 * second_least_sweet;
        heap.insert(new_cookie);
        operations++;
    }
    return -1; // Not possible to achieve sweetness >= k
}

int main() {
    std::vector<int> sweetness = {1, 2, 3, 9, 10, 12};
    int k = 7;
    int result = cookies(k, sweetness);
    std::cout << "Minimum number of operations required: " << result << std::endl;
    return 0;
}
