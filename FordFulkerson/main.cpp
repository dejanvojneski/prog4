#include <iostream>
#include <climits>
using namespace std;

const int V = 6;

bool dfs(int graph[V][V], int source, int sink,
         int parent[], bool visited[]) {

    visited[source] = true;

    if (source == sink)
        return true;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[source][i] > 0) {
            parent[i] = source;

            if (dfs(graph, i, sink, parent, visited))
                return true;
        }
    }

    return false;
}

int fordFulkerson(int graph[V][V], int source, int sink) {
    int residualGraph[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            residualGraph[i][j] = graph[i][j];

    int parent[V];
    int maxFlow = 0;

    while (true) {
        bool visited[V] = {false};
        if (!dfs(residualGraph, source, sink, parent, visited))
            break;

        int pathFlow = INT_MAX;

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];

            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0;
    int sink = 5;

    cout << "Maximum flow: "
         << fordFulkerson(graph, source, sink);

    return 0;
}
