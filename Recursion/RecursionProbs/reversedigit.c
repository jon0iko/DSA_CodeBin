#include<stdio.h>

int revdigit(int n,int rev){
    if(n==0) return rev;
    rev=rev*10+n%10;
    return revdigit(n/10,rev);
}
int main(){
    int n;
    scanf("%d",&n);
    int reverse=revdigit(n,0);
    printf("%d",reverse);
    return 0;
}