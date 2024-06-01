#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<double>& arr) {
    // Find minimum and maximum values
    double minValue = *min_element(arr.begin(), arr.end());
    double maxValue = *max_element(arr.begin(), arr.end());

    // Number of buckets
    int numBuckets = arr.size();

    // Create buckets
    vector<vector<double>> buckets(numBuckets);

    // Distribute elements into buckets
    for (int i = 0; i < arr.size(); ++i) {
        int bucketIndex = (int)((arr[i] - minValue) * (numBuckets - 1) / (maxValue - minValue));
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < numBuckets; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets
    int index = 0;
    for (int i = 0; i < numBuckets; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    // Input numbers
    vector<double> numbers = {3, 0.4458, -0.6651, 0.2222};

    // Sorting using Bucket Sort
    bucketSort(numbers);

    // Output sorted numbers
    cout << "Sorted numbers:" << endl;
    for (double num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}