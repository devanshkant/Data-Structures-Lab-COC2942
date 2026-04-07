#include <iostream>
#include <fstream>
using namespace std;

// Adjacency list node
struct AdjNode {
    int vertex;
    AdjNode* next;
};

// Vertex node
struct Vertex {
    int data;
    AdjNode* adjList;
    Vertex* next;
};

// Graph class
class Graph {
    Vertex* head;

public:
    Graph() {
        head = NULL;
    }

    // Find or create vertex
    Vertex* getVertex(int v) {
        Vertex* temp = head;

        while (temp) {
            if (temp->data == v)
                return temp;
            temp = temp->next;
        }

        Vertex* newV = new Vertex;
        newV->data = v;
        newV->adjList = NULL;
        newV->next = head;
        head = newV;

        return newV;
    }

    // Add edge (undirected)
    void addEdge(int u, int v) {
        Vertex* uNode = getVertex(u);
        Vertex* vNode = getVertex(v);

        AdjNode* newAdj1 = new AdjNode;
        newAdj1->vertex = v;
        newAdj1->next = uNode->adjList;
        uNode->adjList = newAdj1;

        AdjNode* newAdj2 = new AdjNode;
        newAdj2->vertex = u;
        newAdj2->next = vNode->adjList;
        vNode->adjList = newAdj2;
    }

    // Display graph
    void display() {
        Vertex* temp = head;

        while (temp) {
            cout << temp->data << " -> ";
            AdjNode* adj = temp->adjList;

            while (adj) {
                cout << adj->vertex << " ";
                adj = adj->next;
            }
            cout << endl;

            temp = temp->next;
        }
    }
};

int main() {
    Graph g;

    ifstream file("input.txt");

    if (!file) {
        cout << "Error opening file\n";
        return 1;
    }

    int u, v;

    // Read until file ends
    while (file >> u >> v) {
        g.addEdge(u, v);
    }

    file.close();

    cout << "\nAdjacency List:\n";
    g.display();

    return 0;
}