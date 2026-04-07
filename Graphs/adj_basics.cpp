#include <iostream>
#include <fstream>
using namespace std;

// Adjacency node
struct AdjNode {
    int vertex;
    AdjNode* next;
};

// Graph class
class Graph {
    int V;
    AdjNode** adj;
    bool* visited;

public:
    Graph(int vertices) {
        V = vertices;

        adj = new AdjNode*[V + 1];
        visited = new bool[V + 1];

        for (int i = 0; i <= V; i++) {
            adj[i] = NULL;
            visited[i] = false;
        }
    }

    void addEdge(int u, int v) {
        // u → v
        AdjNode* n1 = new AdjNode{v, adj[u]};
        adj[u] = n1;

        // v → u (undirected)
        AdjNode* n2 = new AdjNode{u, adj[v]};
        adj[v] = n2;
    }

    void resetVisited() {
        for (int i = 0; i <= V; i++)
            visited[i] = false;
    }

    void display() {
        for (int i = 0; i <= V; i++) {
            if (adj[i] == NULL) continue;

            cout << i << " -> ";
            AdjNode* temp = adj[i];

            while (temp) {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // DFS
    void DFSUtil(int v) {
        cout << v << " ";
        visited[v] = true;

        AdjNode* temp = adj[v];

        while (temp) {
            if (!visited[temp->vertex]) {
                DFSUtil(temp->vertex);
            }
            temp = temp->next;
        }
    }

    void DFS(int start) {
        resetVisited();
        DFSUtil(start);
        cout << endl;
    }

    // BFS
    void BFS(int start) {
        resetVisited();

        int queue[100];
        int front = 0, rear = 0;

        queue[rear++] = start;
        visited[start] = true;

        while (front < rear) {
            int curr = queue[front++];
            cout << curr << " ";

            AdjNode* temp = adj[curr];

            while (temp) {
                if (!visited[temp->vertex]) {
                    queue[rear++] = temp->vertex;
                    visited[temp->vertex] = true;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main() {
    ifstream file("input.txt");

    int u, v;
    int maxV = -1;

    // 🔹 First pass → find max vertex
    while (file >> u >> v) {
        if (u > maxV) maxV = u;
        if (v > maxV) maxV = v;
    }
    file.close();

    // Create graph
    Graph g(maxV);

    // 🔹 Second pass → build graph
    file.open("input.txt");
    while (file >> u >> v) {
        g.addEdge(u, v);
    }
    file.close();

    cout << "Adjacency List:\n";
    g.display();

    cout << "\nDFS: ";
    g.DFS(1);

    cout << "BFS: ";
    g.BFS(1);

    return 0;
}