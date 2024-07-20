#include <bits/stdc++.h>
using namespace std;

int maxValue(int a, int b) { return (a > b) ? a : b; }

int knapsack(int capacity, int weights[], int values[], int itemCount, vector<int>& includedItems) {
    if (itemCount == 0 || capacity == 0)
        return 0;

    vector<int> tempItems = includedItems;

    if (weights[itemCount - 1] > capacity)
        return knapsack(capacity, weights, values, itemCount - 1, includedItems);

    vector<int> withItem = includedItems;
    withItem.push_back(itemCount - 1);
    int profitWithItem = values[itemCount - 1] + knapsack(capacity - weights[itemCount - 1], weights, values, itemCount - 1, withItem);

    vector<int> withoutItem = includedItems;
    int profitWithoutItem = knapsack(capacity, weights, values, itemCount - 1, withoutItem);

    if (profitWithItem > profitWithoutItem) {
        includedItems = withItem;
        return profitWithItem;
    } else {
        includedItems = withoutItem;
        return profitWithoutItem;
    }
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int maxCapacity = 50;
    int itemCount = sizeof(values) / sizeof(values[0]);

    vector<int> includedItems;
    int maxProfit = knapsack(maxCapacity, weights, values, itemCount, includedItems);

    cout << "Maximum Profit: " << maxProfit << endl;
    cout << "Items included : ";
    for (int item : includedItems) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
