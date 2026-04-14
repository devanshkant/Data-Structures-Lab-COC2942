#ifndef COC2942_ADJ_LIST_H
#define COC2942_ADJ_LIST_H
#include <iostream>
//why use Array + linked list (below)
//Array provides O(1) access, linked list efficiently stores neighbors.
// Adjacency node
struct Node {
    int val; // stores the data of the vertex
    Node* next; // pointer to neighbours
};
// Graph class
class Graph {
    int V;
    // this is an array of linked lists
    Node** adj;
public:
    Graph(int n) {
        // counting no. of vertices 
        V = n;
        //considering 1-based indexing and 
        //labels marked from 1 to V during the input
        //similarly for the visited array
        adj = new Node*[V + 1];
        for (int i = 0; i <= V; i++) {
            adj[i] = nullptr;
        }
    }
    //to prevent shallow copy
    Graph(const Graph&) = delete;
    Graph& operator=(const Graph&) = delete;
    ~Graph() {
        for (int i = 0; i <= V; i++) {
            Node* curr = adj[i];
            while (curr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] adj;
    }
    int size(){
    	return V ;// this will return the number of nodes, 
    				//since it's 1-based, so we return V-1
    }
    void addEdge(int u, int v) {
    	Node* temp = adj[u];
        while (temp) {
            if (temp->val == v) return; // edge already exists
            temp = temp->next;
        }
		Node *n1 = new Node;
		Node *n2 = new Node;
		n1->val = v;
		n1->next = adj[u];
		adj[u] = n1;
		n2->val = u;
		n2->next = adj[v];
		adj[v] = n2;
    }
    void display() {
        for (int i = 1; i <= V; i++) {
            if (adj[i] == nullptr) continue;
            std::cout << i << " -> ";
            Node* temp = adj[i];
            while (temp) {
                std::cout << temp->val << " ";
                temp = temp->next;
            }
            std::cout << '\n';
        }
    }
    // DFS
    void DFS_helper(int v, bool* visited) {
        std::cout << v << " ";
        visited[v] = true;
        Node* temp = adj[v];
        while (temp) {
            if (!visited[temp->val]) {
                DFS_helper(temp->val, visited);
            }
            temp = temp->next;
        }
    }
    void DFS() {
        bool* visited = new bool[V + 1];
        for (int i = 0; i <= V; i++) 
        	visited[i] = false;
        for(int i = 1; i <= V; ++i){
        	if(not visited[i])
		        DFS_helper(i, visited);
		    std::cout << '\n';
        }
        std::cout << '\n';
        delete[] visited;
    }
    // BFS
    void BFS(int start) {
        if (start < 1 || start > V) 
        	return;
        bool* visited = new bool[V + 1];
        for (int i = 0; i <= V; i++)
        	visited[i] = false;
        int queue[100];
        int front = 0, rear = 0;
        queue[rear++] = start;
        visited[start] = true;
        while (front < rear) {
            int curr = queue[front++];
            std::cout << curr << " ";
            Node* temp = adj[curr];
            while (temp) {
                if (!visited[temp->val]) {
                    queue[rear++] = temp->val;
                    visited[temp->val] = true;
                }
                temp = temp->next;
            }
        }
        std::cout << '\n';
        delete[] visited;
    }
};
#endif //COC2942_ADJ_LIST_H