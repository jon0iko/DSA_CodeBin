//n digits,(0-4) indexed,even indexed digits are odd,odd indexed digits are even in descending order

#include<iostream>
#include<algorithm>
using namespace std;

void genCombi(int a[],int l,int sz){
    if(l==sz){
        for(int i=0;i<sz;i++){
            if(i!=0){
                cout<<" ";
            }
              cout<<a[i];
        }
            cout<<endl;
            return ;

        
    }
    for(int i=4;i>=0;i--){
        if(l%2==i%2) continue;
        a[l]=i;
        genCombi(a,l+1,sz);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    
    genCombi(a,0,n);
    return 0;
}