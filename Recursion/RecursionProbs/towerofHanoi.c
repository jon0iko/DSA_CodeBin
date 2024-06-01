#include <stdio.h>

// s source, h helper, d destination
void tower(int n, char s, char h, char d)
{
    if(n==1){  //base case
        printf("Transfer disk %d from %c to %c\n",n,s,d);
        return;
    }
    
        // first move n-1 disks from source to helper,
        // using destination as helper
        tower(n-1, s, d, h);
        // the only left nth disk can be moved directly from source to destination
        printf("Transfer disk %d from %c to %c\n",n, s, d);
        // on first step we've sent n-1 disks to the helper,
        // and now, from the helper, we'll transfer them back to destination
        // using the source as the helper 
        tower(n-1, h, s, d);
    
}

int main()
{
    int n;
    scanf("%d", &n);
    tower(n, 'S', 'H', 'D');
    return 0;
}
