#include <iostream>
using namespace std;

void sortPairs(int arr[][2], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i][0] > arr[j][0] || (arr[i][0] == arr[j][0] && arr[i][1] > arr[j][1])) {
                swap(arr[i][0], arr[j][0]);
                swap(arr[i][1], arr[j][1]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int pair[n][2];
    for (int i = 0; i < n; ++i) {
        cin >> pair[i][0] >> pair[i][1];
    }

    sortPairs(pair, n);

    for (int i = 0; i < n; ++i) {
        cout << pair[i][0] << " " << pair[i][1] << endl;
    }

    return 0;
}
