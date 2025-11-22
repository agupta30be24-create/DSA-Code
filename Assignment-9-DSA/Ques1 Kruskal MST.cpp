#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

struct Edge {
    int u, v, w;
};

int parent[MAX];

int findSet(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findSet(parent[x]);
}

void unionSet(int a, int b) {
    parent[b] = a;
}

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int V, E;
    cin >> V >> E;

    Edge edges[MAX];
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    for (int i = 0; i < V; i++)
        parent[i] = i;

    sort(edges, edges + E, cmp);

    int cost = 0, count = 0;
    cout << "Kruskal MST:\n";

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (findSet(u) != findSet(v)) {
            cout << u << " -- " << v << " (Weight=" << edges[i].w << ")\n";
            cost += edges[i].w;
            unionSet(findSet(u), findSet(v));
            count++;
        }
    }

    cout << "Total Cost = " << cost;
    return 0;
}
