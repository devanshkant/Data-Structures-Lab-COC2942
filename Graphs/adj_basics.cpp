#include <iostream>
#include <fstream>
using namespace std;
//why use Array + linked list (below)
//Array provides O(1) access, linked list efficiently stores neighbors.
// Adjacency node
struct Node {
    int vertex; // stores the data of the vertex
    Node* next; // pointer to neighbours
};

// Graph class
class Graph {
    int V;
    // this is an array of linked lists
    Node** adj;
    bool* visited;

public:
    Graph(int vertices) {
        // counting no. of vertices 
        V = vertices;
        //considering 1-based indexing and 
        //labels marked from 1 to V during the input
        //similarly for the visited array
        adj = new Node*[V + 1];
        visited = new bool[V + 1];

        for (int i = 0; i <= V; i++) {
            adj[i] = nullptr;
            visited[i] = false;
        }
    }

    void addEdge(int u, int v) {
        // u →   v
        Node* n1 = new Node{v, adj[u]};
        adj[u] = n1;

        // v → u (undirected)
        Node* n2 = new Node{u, adj[v]};
        adj[v] = n2;
    }

    void resetVisited() {
        for (int i = 0; i <= V; i++)
            visited[i] = false;
    }

    void display() {
        for (int i = 1; i <= V; i++) {
            if (adj[i] == nullptr) continue;

            cout << i << " -> ";
            Node* temp = adj[i];

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

        Node* temp = adj[v];

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

            Node* temp = adj[curr];

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

    //First pass → find max vertex, 
    //First pass determines maximum vertex index to allocate adjacency array dynamically
    //maxV will store the max label value, which will be the no. of vertices
    while (file >> u >> v) {
        if (u > maxV) maxV = u;
        if (v > maxV) maxV = v;
    }
    file.close();

    // Create graph
    //maxV is the numver of vertices
    Graph g(maxV);

    //Second pass → build graph
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