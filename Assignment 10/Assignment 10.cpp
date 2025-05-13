//
//  main.cpp
//  Data Structures
//
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        // Uncomment the next line if the graph is undirected
        // adj[v].push_back(u);
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "Breadth First Traversal starting from vertex " << start << ": ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;

        visited[start] = true;
        s.push(start);

        cout << "Depth First Traversal starting from vertex " << start << ": ";

        while (!s.empty()) {
            int current = s.top();
            cout << current << " ";

            bool found_unvisited = false;

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                    found_unvisited = true;
                    break;
                }
            }

            if (!found_unvisited) {
                s.pop();
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices (0 to 5)

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.BFS(0);
    g.DFS(0);

    return 0;
}
