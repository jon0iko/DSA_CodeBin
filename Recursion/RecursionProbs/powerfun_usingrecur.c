#include<stdio.h>
double power(int x,int n){
    if(n==0){
        return 1;
    }
    if(n>0) {
         return x*power(x,n-1);
    }
    else {
         n=n*-1;
         return 1/(x*power(x,n-1));
    }
}
int main(){
    int x,n;
    scanf("%d %d",&x,&n);
    //double res=power(x,n);
    printf("%.2lf",power(x,n));
    return 0;
}