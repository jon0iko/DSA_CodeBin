#include <stdio.h>

int binarySearch(int low, int high, int x, int a[])
{
    int mid;
    if(low > high) return -1;
    mid = (low+(high-low))/2;
    if(a[mid]==x) return mid;
    if(a[mid] < x) return binarySearch(mid+1, high, x, a);
    if(a[mid] > x) return binarySearch(low, mid-1, x, a);
    return mid;    
}

int main()
{
    int a[100], n, i, q, v, x;
    scanf("%d", &n);
    // give sorted input
    // otherwise sort the array after taking input
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    scanf("%d", &q);
    for(i=0; i<q; i++)
    {
        scanf("%d", &v);
        x = binarySearch(0, n-1, v, a);
        if(x==-1) printf("Not found\n");
        else printf("Found at %d\n", x);
    }
    return 0;
}
