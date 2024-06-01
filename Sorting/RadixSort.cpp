#include<iostream>
using namespace std;

//modified counting sort for using in radix sort
void countSort(int arr[], int n,int place) {
    int k = (arr[0]/place)%10;
    for (int i = 0; i < n; i++) {
        k = max(k, ((arr[i]/place)%10));
    }
    
    const int size = k + 1;
    int count[size] = {0};
    for(int i=0;i<n;i++){
        count[(arr[i]/place)%10]++; //count of every element
    }

    //modify count array by cummulative sum
    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        //predecrement then store
        output[--count[(arr[i]/place)%10]]=arr[i];
    }
    //output array ke again og array te transfer
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

void radixSort(int arr[],int n){
    int m = arr[0];
    for (int i = 0; i < n; i++) {
        m = max(m, arr[i]);
    }
    for(int i=1;m/i>0;i*=10){
        countSort(arr,n,i); 
    }
}

int main(){
     int arr[]={5,122,98,232,140};
    radixSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
} 