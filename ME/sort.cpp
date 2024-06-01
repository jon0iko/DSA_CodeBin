#include <bits/stdc++.h>
using namespace std;

// void countSort(int arr[], int n)
// {
//     int k = arr[0];
//     for (int i = 0; i < n; i++)
//     {
//         k = max(k, arr[i]);
//     }

//     const int size = k + 1;
//     int count[size] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         count[arr[i]]++; // count of every element
//     }

//     // modify count array
//     for (int i = 1; i <= k; i++)
//     {
//         count[i] += count[i - 1];
//     }
//     int output[n];
//     for (int i = n - 1; i >= 0; i--)
//     {
//         // predecrement then store
//         output[--count[arr[i]]] = arr[i];
//     }
//     // output array ke again og array te transfer
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = output[i];
//     }
// }

void countSort(int arr[], int n) {
    int k = arr[0],l=arr[0];
    for (int i = 1; i < n; i++) {
        k = max(k, arr[i]);
        l = min(l, arr[i]);
    }
    
    const int range = k -l+1;
    int count[range] = {0};
    for(int i=0;i<n;i++){
        count[arr[i]-l]++; 
    }

    for(int i=1;i<range;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]-l]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

void countSortR(int arr[], int n, int place)
{
    int k = (arr[0] / place) % 10;
    for (int i = 0; i < n; i++)
    {
        k = max(k, ((arr[i] / place) % 10));
    }

    const int size = k + 1;
    int count[size] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / place) % 10]++; // count of every element
    }

    // modify count array by cummulative sum
    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        // predecrement then store
        output[--count[(arr[i] / place) % 10]] = arr[i];
    }
    // output array ke again og array te transfer
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int m = arr[0];
    for (int i = 0; i < n; i++)
    {
        m = max(m, arr[i]);
    }
    for (int i = 1; m / i > 0; i *= 10)
    {
        countSortR(arr, n, i);
    }
}

// Insertion sort function to sort individual buckets
void insertionSort(vector<float>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}


void bucketSort(float arr[], int n) {
    // 1) Find the minimum and maximum values to determine the range
    float minVal = *min_element(arr, arr + n);
    float maxVal = *max_element(arr, arr + n);

    // 2) Create n empty buckets
    vector<float> buckets[n];

    // 3) Calculate the range for each bucket
    float range = maxVal - minVal;

    // 4) Put array elements into different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * (arr[i] - minVal) / range; // Normalize to [0, n)
        if (bucketIndex >= n) bucketIndex = n - 1; // Ensure the index is within bounds
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 5) Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i]);
    }

    // 6) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}



int main()
{
    float arr[] = {-0.6,2.6,1.5,1.2,0.2,0.5,0.3,0.1,0.4};

    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}
