#include<iostream>
using namespace std;


void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        // Last i elements are already sorted, so no need to check them
        for (int j = 0; j < size - i - 1; ++j) {
            // Swap adjacent elements if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main(){
    int a[]={1,3,2,3,4,1,6,4,3};
    bubbleSort(a,9);
    for(int i=0;i<9;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}