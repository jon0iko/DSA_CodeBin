#include<stdio.h>

void pintu(int a[],int n,int i,int j){
    if(i>j)
    {
        return;
    }
    printf("%d %d\n",a[i],a[j]);
    pintu(a,n,i+1,j-1);
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    pintu(arr,n,0,n-1);
    return 0;
}