#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to, cost;
};

struct Graph {
    int numVertices, numEdges;
    Edge* edges;
};

Graph* createGraph(int numVertices, int numEdges) {
    Graph* g = new Graph;
    g->numVertices = numVertices;
    g->numEdges = numEdges;
    g->edges = new Edge[numEdges];
    return g;
}

void displayDistances(int distances[], int numVertices) {
    for (int i = 0; i < numVertices; ++i)
        cout << "Vertex " << i << ": " << distances[i] << endl;
}

void findShortestPaths(Graph* g, int start) {
    int V = g->numVertices;
    int E = g->numEdges;
    int distances[V];

    for (int i = 0; i < V; i++)
        distances[i] = numeric_limits<int>::max();
    distances[start] = 0;

    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            Edge& e = g->edges[j];
            if (distances[e.from] != numeric_limits<int>::max() && distances[e.from] + e.cost < distances[e.to])
                distances[e.to] = distances[e.from] + e.cost;
        }
    }

    for (int i = 0; i < E; i++) {
        Edge& e = g->edges[i];
        if (distances[e.from] != numeric_limits<int>::max() && distances[e.from] + e.cost < distances[e.to]) {
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }

    displayDistances(distances, V);
}

int main() {
    int V = 5;
    int E = 8;
    Graph* g = createGraph(V, E);

    Edge edges[] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    for (int i = 0; i < E; ++i) {
        g->edges[i] = edges[i];
    }

    findShortestPaths(g, 0);

    delete[] g->edges;
    delete g;

    return 0;
}
