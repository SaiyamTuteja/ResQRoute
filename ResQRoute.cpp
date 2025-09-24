#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int to;
    int weight;
};

// Graph represented as adjacency list
vector<vector<Edge>> graph;

// Function to add an edge to the graph
void addEdge(int u, int v, int w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w}); // Assuming undirected graph for routes
}

// Dijkstra's algorithm to find shortest path from source to destination
pair<int, vector<int>> dijkstra(int source, int destination, int n) {
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Reconstruct path
    vector<int> path;
    if (dist[destination] == INT_MAX) {
        return {INT_MAX, path}; // No path
    }

    for (int v = destination; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    return {dist[destination], path};
}

int main() {
    int n, m; // n: number of places, m: number of routes

    // Explanation of input types
    cout << "=== ResQRoute: Disaster Response Route Finder ===\n";
    cout << "This program finds the shortest route between two places in a disaster scenario.\n";
    cout << "Input format:\n";
    cout << "- Number of places (nodes): Integer representing total locations (e.g., 5 for places 0 to 4).\n";
    cout << "- Number of routes (edges): Integer representing connections between places.\n";
    cout << "- Routes: For each route, enter 'u v w' where:\n";
    cout << "  * u: Starting place (integer from 0 to n-1)\n";
    cout << "  * v: Ending place (integer from 0 to n-1)\n";
    cout << "  * w: Weight (e.g., distance in km or time in minutes)\n";
    cout << "- Source place: Starting location for the route (integer from 0 to n-1).\n";
    cout << "- Destination place: Target location for the route (integer from 0 to n-1).\n";
    cout << "Example: If places are 0,1,2 and routes are 0-1:5, 1-2:3, source=0, dest=2\n";
    cout << "Enter number of places (nodes): ";
    cin >> n;
    cout << "Enter number of routes (edges): ";
    cin >> m;

    graph.resize(n);

    cout << "Enter routes (u v w) where u and v are places, w is weight (e.g., distance or time):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    int source, destination;
    cout << "Enter source place: ";
    cin >> source;
    cout << "Enter destination place: ";
    cin >> destination;

    auto result = dijkstra(source, destination, n);
    int distance = result.first;
    vector<int> path = result.second;

    if (distance == INT_MAX) {
        cout << "No route found from " << source << " to " << destination << endl;
    } else {
        cout << "Shortest distance: " << distance << endl;
        cout << "Path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
