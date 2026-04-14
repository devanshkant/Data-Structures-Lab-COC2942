#include "adj_list.h"
using namespace std;

bool dfs_cycle_undirected(Graph &g, int curr, bool visited[], int parent){
    visited[curr] = true;

    Node* temp = g.getAdjList(curr);

    while(temp){
        int neigh = temp->val;

        if(!visited[neigh]){
            if(dfs_cycle_undirected(g, neigh, visited, curr))
                return true;
        }
        else if(neigh != parent){
            return true; // cycle found
        }

        temp = temp->next;
    }

    return false;
}

bool hasCycleUndirected(Graph &g){
    int V = g.size();
    bool* visited = new bool[V + 1];

    for(int i = 0; i <= V; i++)
        visited[i] = false;

    for(int i = 1; i <= V; i++){
        if(!visited[i]){
            if(dfs_cycle_undirected(g, i, visited, -1)){
                delete[] visited;
                return true;
            }
        }
    }

    delete[] visited;
    return false;
}