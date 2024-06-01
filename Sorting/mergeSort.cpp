#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int h)
{

    int n1 = mid - l + 1;
    int n2 = h - mid;
    // making two temp arrays
    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i]; // bcz starting point is l
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i]; // bcz starting point is mid+1
    }

    int cur1 = 0, cur2 = 0;
    int i = l;
    while (cur1 < n1 && cur2 < n2)
    {
        if (a[cur1] < b[cur2])
        {
            arr[i] = a[cur1];
            i++;
            cur1++;
        }
        else
        {
            arr[i] = b[cur2];
            i++;
            cur2++;
        }
    }
    while (cur1 < n1)
    {
        arr[i] = a[cur1];
        i++;
        cur1++;
    }

    while (cur2 < n2)
    {
        arr[i] = b[cur2];
        i++;
        cur2++;
    }
}

void mergeSort(int arr[], int low, int high)
{

    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[]={5,7,3,2,1};
    mergeSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}