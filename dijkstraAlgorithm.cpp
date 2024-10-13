#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> Pair;

void dijkstra(int source, vector<vector<Pair>>& adjList, int V) {
    vector<int> dist(V, INT_MAX);
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<Pair>> adjList(V);

    adjList[0].push_back({1, 9});
    adjList[0].push_back({2, 6});
    adjList[0].push_back({3, 5});
    adjList[0].push_back({4, 3});
    adjList[2].push_back({1, 2});
    adjList[2].push_back({3, 4});

    dijkstra(0, adjList, V);

    return 0;
}
