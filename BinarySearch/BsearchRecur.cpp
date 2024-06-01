#include <iostream>

// Recursive function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // If the target is found at the middle
        if (arr[mid] == target)
            return mid;

        // If the target is greater, search the right half
        if (arr[mid] < target)
            return binarySearch(arr, mid + 1, right, target);

        // If the target is smaller, search the left half
        return binarySearch(arr, left, mid - 1, target);
    }

    // If the target is not found in the array
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int index = binarySearch(arr, 0, size - 1, target);

    if (index != -1)
        std::cout << "Element found at index: " << index << std::endl;
    else
        std::cout << "Element not found in the array." << std::endl;

    return 0;
}
