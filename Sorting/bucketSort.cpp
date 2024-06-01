#include <iostream>
#include<algorithm>

using namespace std;

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; ++i) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void bucketSort(float arr[], int n) {
    // Find maximum and minimum values in the array
    float minValue = arr[0];
    float maxValue = arr[0];
    for (int i = 1; i < n; i++) {
        minValue = min(minValue, arr[i]);
        maxValue = max(maxValue, arr[i]);
    }

    // Calculate the range of each bucket
    float range = (maxValue - minValue) / n;

    // Create an array of arrays (buckets)
    const int numOfBuckets = n;
    const int maxBucketSize = n; // Assuming each bucket can contain all elements
    float buckets[numOfBuckets][maxBucketSize];
    int bucketCounts[numOfBuckets] = {0};

    // Put array elements into buckets
    for (int i = 0; i < n; i++) {
        
        int bucketIndex = (arr[i] - minValue) / range;
        //boundary ele
        float diff=(arr[i]-minValue)/range-bucketIndex;
        if(diff==0 && arr[i]!=minValue){
             buckets[bucketIndex-1][bucketCounts[bucketIndex]++] = arr[i];
        }
        else {
        buckets[bucketIndex][bucketCounts[bucketIndex]++] = arr[i];
    }
    }

    // Sort individual buckets
    for (int i = 0; i < numOfBuckets; i++) {
        insertionSort(buckets[i], bucketCounts[i]);
    }

    // Concatenate sorted buckets into original array
    int index = 0;
    for (int i = 0; i < numOfBuckets; i++) {
        for (int j = 0; j < bucketCounts[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    float arr[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    
    bucketSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
