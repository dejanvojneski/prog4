#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> am;
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
    cout << u << " ";
    for (int v = 0; v < n; v++)
        if (am[u][v] && !vis[v]) dfs(v);
}

void bfs(int s) {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v = 0; v < n; v++)
            if (am[u][v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
    cout << "\nDistances from " << s << ": ";
    for (int i = 0; i < n; i++) cout << dist[i] << " ";
    cout << "\n";
}

int main() {
    cin >> n >> m;
    am.assign(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        am[u][v] = 1;
        am[v][u] = 1;          
    }
    int s;
    cin >> s;

    vis.assign(n, false);
    cout << "DFS order: ";
    dfs(s);
    cout << "\n";

    cout << "BFS order: ";
    bfs(s);
    return 0;
}