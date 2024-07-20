//buvket sort algorithm works on distribute your data into buckets, sorting each bucket, and then combine them to get the final sorted result
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void insertionSort(vector<int>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucketSort(int data[], int size) {
    int maxValue = *max_element(data, data + size);
    vector<int> buckets[size];

    for (int i = 0; i < size; i++) {
        int index = (data[i] * size) / (maxValue + 1);
        buckets[index].push_back(data[i]);
    }

    for (int i = 0; i < size; i++) {
        insertionSort(buckets[i]);
    }

    int pos = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            data[pos++] = buckets[i][j];
        }
    }
}

int main() {
    int data[] = {89, 65, 78, 12, 66, 34};
    int size = sizeof(data) / sizeof(data[0]);
    bucketSort(data, size);

    cout << "Sorted array is \n";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    return 0;
}
