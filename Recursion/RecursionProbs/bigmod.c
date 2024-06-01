#include<stdio.h>

int bigmod(int a,int n,int b){
    long long  y;
    if(a==0) return 0;  //base case
    if(n==0) return 1; //base case
    if(n%2==0){   //if power is even
        y=bigmod(a,n/2,b);
        y=(y*y)%b;
    }
    else { //when power is odd
        y=a%b;
        y=(y*bigmod(a,n-1,b)%b)%b;
    }
    return (int)((y+b)%b);

}
int main() {
    int a,n,b;
    scanf("%d %d %d",&a,&n,&b);
    int result=bigmod(a,n,b);
    printf("%d\n",result);
    return 0;
}
