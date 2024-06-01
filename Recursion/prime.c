 #include<stdio.h>

 int prime(int n){
    int i;
    
    for(i=2;i<=n-1;i++){
        if(n%i==0){
            return 0;
        }
    }
    if(i==n){
   return 1;
    } 
   
 }
 int main()
{
    int n1,n2, i=2;
    printf("Enter the starting number: ");
    scanf("%d",&n1);
    printf("Enter the ending number: ");
    scanf("%d",&n2);

    while (n1<=n2)
    {
        if (prime(n1))
        {
            printf("%d is a prime\n",n1);
        }
        else
        {
            printf("%d is not a prime\n",n1);
        }
        n1++;
    }
    
    
    return 0;

}