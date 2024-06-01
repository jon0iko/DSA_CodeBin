#include <iostream>

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If the target is found at the middle
        if (arr[mid] == target)
            return mid;

        // If the target is greater, ignore the left half
        if (arr[mid] < target)
            left = mid + 1;

        // If the target is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // If the target is not found in the array
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int index = binarySearch(arr, size, target);

    if (index != -1)
        std::cout << "Element found at index: " << index << std::endl;
    else
        std::cout << "Element not found in the array." << std::endl;

    return 0;
}
