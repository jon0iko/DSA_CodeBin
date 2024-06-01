#include <iostream>
#include <algorithm>
using namespace std;

// Function to perform binary search
bool binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return true;  // Element found
        } else if (arr[mid] < target) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }
    return false;  // Element not found
}

int main() {
    int n, q;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
   
    
    cin >> q;
    int query[q];
    for (int i = 0; i < q; i++) {
        cin >> query[i];
    }
    
    
    for (int i = 0; i < q; i++) {
        int qu = query[i];
        bool found = binarySearch(nums, n, qu);
        cout << (found ? 1 : 0) << endl;
    }

    return 0;
}
