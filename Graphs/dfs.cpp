#include"adj_list.h"
using namespace std;

// DFS
void DFS_helper(Graph &g, int v, bool* visited) {
    std::cout << v << " ";
    visited[v] = true;
    Node* temp = g.getAdjList(v);
    while (temp) {
        if (!visited[temp->val]) {
            DFS_helper(g, temp->val, visited);
        }
        temp = temp->next;
    }
}
void DFS(Graph &g) {
    int V = g.size();
    bool* visited = new bool[V + 1];
    for (int i = 0; i <= V; i++) 
    	visited[i] = false;

    for(int i = 1; i <= V; ++i){
    	if(not visited[i])
	        DFS_helper(g, i, visited);
	    std::cout << '\n';
    }
    std::cout << '\n';
    delete[] visited;
}