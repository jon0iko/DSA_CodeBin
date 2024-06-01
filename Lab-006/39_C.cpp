#include<iostream>
using namespace std;


int arr[100000];
int size = 0; 

int insert(int v) {
   
    arr[size] = v;
    size++;

    int current = size - 1;
    while (current > 0 && arr[current] < arr[(current - 1) / 2]) {
        int temp = arr[current];
        arr[current] = arr[(current - 1) / 2];
        arr[(current - 1) / 2] = temp;

        current = (current - 1) / 2;
    }
    return 0;
}


int deleteH(int x) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == x) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return -1; 
    }

    arr[index] = arr[size - 1];
    size--;

    int current = index;
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
    return x; 
}


int min() {
   // int size=0;
    if(size == 0) return -1;
    return arr[0];
}

int main() {
    int qNo;
    cin >> qNo;
    while (qNo--) {
        int qType, v;
        cin >> qType;
        if (qType == 1) {
            cin>>v;
            insert(v);
        }
        else if (qType == 2) {
            cin>>v;
            deleteH(v);
        }
        else if (qType == 3) {
            cout << min() << endl;
        }
    }
}
