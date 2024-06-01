#include<stdio.h>
int len=0;
void remov(int a[],int n,int i,int j){
    if(i>n-1)
    {
        return ;
    }
    if(a[i]%2==0) {
        a[j++]=a[i];
        len++;
    }
    
    remov(a,n,i+1,j);
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    remov(arr,n,0,0);
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}