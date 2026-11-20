#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void DFS(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor);
        }
    }
}

void BFS(int start, int n) {
    fill(visited.begin(), visited.end(), false);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, edges;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> edges;

    graph.resize(n);
    visited.resize(n, false);

    cout << "Enter edges:\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS: ";
    fill(visited.begin(), visited.end(), false);
    DFS(start);

    cout << "\nBFS: ";
    BFS(start, n);

    return 0;
}