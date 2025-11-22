#include <iostream>
using namespace std;

#define INF 999999
#define MAX 100

int graph[MAX][MAX];

int main() {
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = graph[v][u] = w;
    }

    int key[MAX], parent[MAX], inMST[MAX];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        inMST[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;

        for (int i = 0; i < V; i++)
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;

        inMST[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] > 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Prim MST:\n";
    int cost = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " -- " << i << " (Weight=" << key[i] << ")\n";
        cost += key[i];
    }

    cout << "Total Cost = " << cost;
    return 0;
}
