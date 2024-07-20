#include <bits/stdc++.h>
using namespace std;

#define N 4

void findTSP(int graph[][N], vector<bool>& visited, int pos, int n, int count, int cost, int& minCost)
{
    if (count == n && graph[pos][0]) {
        minCost = min(minCost, cost + graph[pos][0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = true;
            findTSP(graph, visited, i, n, count + 1, cost + graph[pos][i], minCost);
            visited[i] = false;
        }
    }
}

int main()
{
    int n = 4;
    int graph[][N] = {
        { 0, 10, 15, 20 },
        { 10, 0, 35, 25 },
        { 15, 35, 0, 30 },
        { 20, 25, 30, 0 }
    };

    vector<bool> visited(n, false);
    visited[0] = true;
    int minCost = INT_MAX;

    findTSP(graph, visited, 0, n, 1, 0, minCost);

    cout << minCost;

    return 0;
}
