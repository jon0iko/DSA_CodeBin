#include<iostream>
using namespace std;

void countSort(string& s,int n) {
    char maxChar=0;
    for (int i = 0; i < n; i++) {
        maxChar = max(maxChar,s[i]);
    }
    
    const int size = maxChar + 1;
    int count[size] = {0};
    for(int i=0;i<n;i++){
        count[s[i]]++; //count of every element
    }

    //modify count array 
    for(int i=1;i<=maxChar;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        //predecrement then store
        output[--count[s[i]]]=s[i];
    }
    //output array ke again og array te transfer
    for(int i=0;i<n;i++){
        s[i]=output[i];
    }
}


int main(){
    string s1;
    cin>>s1;
    int len=s1.length();
    countSort(s1,len);
    cout<<s1<<endl;
    
    return 0;
}