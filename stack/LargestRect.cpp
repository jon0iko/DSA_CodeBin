//hoy nai pari nai vul code

#include<iostream>
#include<stack>
using namespace std;

int getMaxArea(int arr[],int n){
    stack<int> s;
    int max_area = 0;
    int tp; //to store top of stack
    int area_with_top; //to store area with top element as smallest bar
    int i=0;
    while(i<n){
        if(s.empty() || arr[s.top()]<=arr[i]){
            s.push(i++);
        }
        else {
            tp=s.top();
            s.pop();
            area_with_top=arr[tp]*(s.empty()?i:i-s.top()-1);
            if(max_area<area_with_top){
                max_area=area_with_top;
            }
        }

        while(s.empty()==false){
            tp=s.top();
            s.pop();
            area_with_top=arr[tp]*(s.empty()?i:i-s.top()-1);
            if(max_area<area_with_top){
                max_area=area_with_top;
            }
            return max_area;
        }
    }
}

int getmax(int arr[],int n){
    stack<int> st;
    int ans=0,i=0;
    arr[n]=0;
    while(i<n){
        while(!st.empty() && arr[st.top()]>arr[i]){
            int t=st.top();
            int h=arr[t];
            if(st.empty()){
                ans=max(ans,h*i);
            }
            else {
                int len=i=st.top()-1;
                ans=max(ans,h*len);
            }
        
        st.push(i);
        i++;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<getmax(a,n);
    //delete[] a; // deallocate the memory
}