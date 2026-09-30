#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> el;
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
    cout << u << " ";
    for (auto [a, b] : el) {
        if (a == u && !vis[b]) dfs(b);
        else if (b == u && !vis[a]) dfs(a);   // remove this line for directed graph
    }
}

void bfs(int s) {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (auto [a, b] : el) {
            int v = -1;
            if (a == u) v = b;
            else if (b == u) v = a;             // remove this line for directed graph
            if (v != -1 && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << "\nDistances from " << s << ": ";
    for (int i = 0; i < n; i++) cout << dist[i] << " ";
    cout << "\n";
}

int main() {
    cin >> n >> m;
    el.resize(m);
    for (int i = 0; i < m; i++) cin >> el[i].first >> el[i].second;
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