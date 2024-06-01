#include<iostream>
#include<vector>
using namespace std;

void heapi(vector<int> &a,int n,int i){
    int maxIdx=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left]>a[maxIdx]){
        maxIdx=left;
    }
    if(right<n && a[right]>a[maxIdx]){
        maxIdx=right;
    }
    if(maxIdx!=i){
        swap(a[i],a[maxIdx]);
        heapi(a,n,maxIdx);
    }
}
void heapSort(vector<int> &a){
    int n=a.size();
    for(int i=n/2-1;i>=0;i--){
        heapi(a,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        heapi(a,i,0);
    }



}



int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    heapSort(a);
    cout<<"[";
    for(int i=0;i<n;i++){
        if(i==n-1){
            cout<<a[i];
            break;
        }
        else
        cout<<a[i]<<",";
    }
    cout<<"]";
    return 0;
}