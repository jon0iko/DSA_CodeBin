#include<stdio.h>
#include<math.h>

int sum_of_series(int n, int x,int i){
    if(n==0){
        return 1;
    }
    if(i<=n-1){
        return  pow(x,i)+sum_of_series(n,x,i+1);
        
    }
    return 0;
}

int main(){
    int n,x,result;
    scanf("%d %d",&x,&n);
    result=sum_of_series(n,x,0);
    printf("%d",result);
    return 0;
}