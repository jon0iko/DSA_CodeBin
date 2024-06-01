#include<iostream>
#include<algorithm>
using namespace std;

void CountSort(int arr[],int n){
    int maxElement = *std::max_element(arr, arr + n);
    int minElement = *std::min_element(arr, arr + n);
    int range = maxElement - minElement + 1;

    int count[range] = {0};
    int output[n];

    for (int i = 0; i < n; i++)
        count[arr[i] - minElement]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minElement] - 1] = arr[i];
        count[arr[i] - minElement]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}




int main(){
    int a[]={1,3,2,3,4,1,6,4,3};
    CountSort(a,9);
    for(int i=0;i<9;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}