#include<iostream>
#include<algorithm>
using namespace std;

void combi(int arr[],int data[],int st,int ed,int idx,int r);

void printCombi(int arr[],int n,int r){
    int data[r];
    combi(arr,data,0,n-1,0,r);

}
    
void combi(int arr[],int data[],int start,int end,int idx,int r){
    if(idx==r){
        for(int i=0;i<r;i++){
          
            cout<<data[i]<<" ";
        }
            cout<<endl;
            return;
        
    }
        for(int i=start;i<=end && end-i+1>=r-idx;i++){
            data[idx]=arr[i];
            combi(arr,data,i+1,end,idx+1,r);
        
    }
}

//include and exclude every element method (sir dekhaise)
void combi2(int arr[],int n,int r,int index,int data[],int i);

void printCombi2(int arr[],int n,int r){
    int data[r];
    combi2(arr,n,r,0,data,0);
}
void combi2(int arr[],int n,int r,int index,int data[],int i){ //i=index of current element in arr
    if(index==r){
        for(int i=0;i<r;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(i>=n){
        return;
    }
    data[index]=arr[i];
    combi2(arr,n,r,index+1,data,i+1);
    combi2(arr,n,r,index,data,i+1);
}
//handling duplicates 1 2 and 2 1 are same
//steps: sort the array before calling combi in printcombi
//check if the current element is same as the previous element then skip it

void combi3(int arr[],int n,int r,int index,int data[],int i);

void printCombi3(int arr[],int n,int r){
    int data[r];
    sort(arr,arr+n);
    combi3(arr,n,r,0,data,0);
}

void combi3(int arr[],int n,int r,int index,int data[],int i){
    if(index==r){
        for(int i=0;i<r;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(i>=n){
        return;
    }
    data[index]=arr[i];
    combi3(arr,n,r,index+1,data,i+1);
    while(i<n-1 && arr[i]==arr[i+1]){
        i++;
    }
    combi3(arr,n,r,index,data,i+1);
}


int main(){
    int arr[]={1,2,1};
    int r=2;
    int n=sizeof(arr)/sizeof(arr[0]);
    printCombi3(arr,n,r);
    return 0;
}