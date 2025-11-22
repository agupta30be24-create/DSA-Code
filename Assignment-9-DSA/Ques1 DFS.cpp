#include <iostream>
using namespace std;

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

void DFSUtil(int u, int V) {
    visited[u] = 1;
    cout << u << " ";

    for (int v = 0; v < V; v++) {
        if (graph[u][v] > 0 && !visited[v])
            DFSUtil(v, V);
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    cout << "DFS Traversal: ";
    DFSUtil(0, V);
    return 0;
}
