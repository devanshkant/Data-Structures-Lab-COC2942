#include"adj_list.h"
using namespace std;

// BFS
void BFS(Graph &g, int start) {
    int V = g.size();

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
        Node* temp = getAdjList(curr);
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

