//sorted
//ascending(non-decreasing)
//0-based index
//if target not present return [-1,-1]

#include<iostream>
#include<vector>
using namespace std;


int lowerBound(vector<int> &inp,int target){ //first idx >=target
  int lo=0,hi=inp.size()-1;
  int ans=-1;
  while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(inp[mid]>=target){
        ans=mid;
        hi=mid-1;
    
    }else{
        lo=mid+1;
    }

  }
  return ans;

}

int upperBound(vector<int> &inp,int target){ //first idx >target
  int lo=0,hi=inp.size()-1;
  int ans=-1;
  while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(inp[mid]>target){
        ans=mid;
        hi=mid-1; //discard right side
    }else{
        lo=mid+1;
    }

  }
  return ans;

}

 

int main(){
    int n;cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int target;cin>>target;
    vector<int> result;
    int lb=lowerBound(arr,target);
    if(arr[lb]!=target){
        result={-1,-1};
    }
    else{
        int ub=upperBound(arr,target);
        result.push_back(lb);
        result.push_back(ub-1);
    } 
    cout<<result[0]<<" "<<result[1]<<endl;

    return 0;
}