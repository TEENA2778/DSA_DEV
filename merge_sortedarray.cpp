#include<iostream>
#include<array>
using namespace std;

int main() {
    int a[] = {5, 8, 7, 2};
    int b[] = {1, 3, 6, 4};
    int c[8]; // Array to hold the merged elements
    int k = 0, i = 0, j = 0;

    // Merge and sort arrays a and b into array c
    while (i < 4 && j < 4) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    // Add remaining elements from a
    while (i < 4) {
        c[k] = a[i];
        i++;
        k++;
    }

    // Add remaining elements from b
    while (j < 4) {
        c[k] = b[j];
        j++;
        k++;
    }

    // Print the merged array
    for (int x = 0; x < k; x++) {
        cout << c[x] << " ";
    }

    return 0;
}

