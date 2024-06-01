//sort the items in queue is ascending order  or using bucket sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ll {

    struct Node {
        double value;
        Node* next;
    };

    Node* head = NULL;
    Node* tail = NULL;

    void insert_stack(double data) {
        Node* newNode = new Node();
        newNode->value = data;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = NULL;
        }
    }

    void push(double data) {
        insert_stack(data);
    }

    void print() {
        Node* p = head;
        while (p) {
            cout << p->value<<endl;
            p = p->next;
        }
        //cout << endl;
    }

   

    

    void sort() {
        Node* current = head;
        Node* index = NULL;
        double temp;

        if (head == NULL) {
            return;
        } else {
            while (current != NULL) {
                // index points to the node next to current
                index = current->next;

                while (index != NULL) {
                    if (current->value > index->value) {
                        temp = current->value;
                        current->value = index->value;
                        index->value = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
};

//bucket sort
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
    for(int i = 0; i < numBuckets; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets
    int index = 0;
    for(int i = 0; i < numBuckets; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}


int main() {
    int n;
    cin >> n;
    double i,v;
    ll list;
    for (i = 0; i < n; i++) {
        cin >> v;
        list.insert_stack(v);
    }

    list.sort();  // Corrected the function call
    list.print();
    return 0;
}