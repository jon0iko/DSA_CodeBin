//n numbers of window, k size of the windows, find the sum of the windows from left to right
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Calculate the sum of the first window
    int windowSum = 0;
    for (int i = 0; i < k; ++i) {
        windowSum += arr[i];
    }
    cout << windowSum << endl;

    // Move the window and calculate the sum for each subsequent window
    for (int i = 1; i <= n - k; ++i) {
        windowSum = windowSum - arr[i - 1] + arr[i + k - 1];
        cout << windowSum << endl;
    }

    return 0;
}