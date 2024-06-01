#include <iostream>
#include <algorithm>
using namespace std;

void bucketSort(float arr[], int n) {
    // Find maximum and minimum values in the array
    float minValue = arr[0];
    float maxValue = arr[0];
    for (int i = 1; i < n; i++) {
        minValue = std::min(minValue, arr[i]);
        maxValue = std::max(maxValue, arr[i]);
    }

    // Calculate the range of each bucket
    float range = (maxValue - minValue) / n;

    // Create an array of pointers to linked lists (buckets)
    struct Node {
        float data;
        Node* next;
    };
    Node* buckets[n] = {nullptr};

    // Put array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - minValue) / range;
        Node* newNode = new Node{arr[i], nullptr};
        if (!buckets[bucketIndex]) {
            buckets[bucketIndex] = newNode;
        } else {
            // Insert newNode at the head of the bucket
            newNode->next = buckets[bucketIndex];
            buckets[bucketIndex] = newNode;
        }
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        Node* head = buckets[i];
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            prev = curr;
            curr = curr->next;
        }
        // Now prev points to the last node in the bucket
        // Sort the bucket using insertion sort
        Node* sorted = nullptr;
        while (head) {
            Node* temp = head;
            head = head->next;
            if (!sorted || temp->data < sorted->data) {
                temp->next = sorted;
                sorted = temp;
            } else {
                Node* prev = sorted;
                Node* curr = sorted->next;
                while (curr && curr->data < temp->data) {
                    prev = curr;
                    curr = curr->next;
                }
                prev->next = temp;
                temp->next = curr;
            }
        }
        buckets[i] = sorted; // Update the head of the bucket
    }

    // Concatenate sorted buckets into original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr) {
            arr[index++] = curr->data;
            curr = curr->next;
        }
    }

    // Delete dynamically allocated memory for buckets
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
}

int main() {
    float arr[] = {2.42, 5.32, 3.33, -1.52, 4.37, 7.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

  

    bucketSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
