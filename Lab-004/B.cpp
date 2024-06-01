//n digits,(0-4) indexed,even indexed digits are even,odd indexed digits are odd
#include <bits/stdc++.h>
using namespace std;

void generatecombi(int arr[],int key,int n){
    if(key==n){
        cout<<arr[0];
        for(int i=1;i<n;i++){
            cout<<" "<<arr[i];
        }
        cout<<endl;
        return;
    }
    if(key%2==0){
        for(int i=0;i<5;i+=2){
            arr[key]=i;
            generatecombi(arr,key+1,n);
        }
    }
    else {
        for(int i=1;i<5;i+=2){
            arr[key]=i;
            generatecombi(arr,key+1,n);
    }
}
}



int main()
{
    int n;
    cin >> n;
    int arr[n];
    generatecombi(arr,0,n);
}