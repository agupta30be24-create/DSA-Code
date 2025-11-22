#include <iostream>
using namespace std;

#define MAX 100

int graph[MAX][MAX];

void BFS(int start, int V) {
    int visited[MAX] = {0};
    int q[MAX], front = 0, rear = 0;

    visited[start] = 1;
    q[rear++] = start;

    cout << "BFS Traversal: ";
    while (front < rear) {
        int u = q[front++];

        cout << u << " ";
        for (int v = 0; v < V; v++) {
            if (graph[u][v] > 0 && !visited[v]) {
                visited[v] = 1;
                q[rear++] = v;
            }
        }
    }
    cout << endl;
}

int main() {
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    BFS(0, V);
    return 0;
}
