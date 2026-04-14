#include "adj_list.h"
using namespace std;

bool dfs_path_undirected(Graph &g, int curr, int dest, bool visited[]){
    if(curr == dest)
        return true;

    visited[curr] = true;

    Node* temp = g.getAdjList(curr);

    while(temp){
        int neigh = temp->val;

        if(!visited[neigh]){
            if(dfs_path_undirected(g, neigh, dest, visited))
                return true;
        }

        temp = temp->next;
    }

    return false;
}

bool pathExistsUndirected(Graph &g, int src, int dest){
    int V = g.size();

    bool* visited = new bool[V + 1];
    for(int i = 0; i <= V; i++)
        visited[i] = false;

    bool result = dfs_path_undirected(g, src, dest, visited);

    delete[] visited;
    return result;
}

bool dfs_path_directed(Graph &g, int curr, int dest, bool visited[]){
    if(curr == dest)
        return true;

    visited[curr] = true;

    Node* temp = g.getAdjList(curr);

    while(temp){
        int neigh = temp->val;

        if(!visited[neigh]){
            if(dfs_path_directed(g, neigh, dest, visited))
                return true;
        }

        temp = temp->next;
    }

    return false;
}

bool pathExistsDirected(Graph &g, int src, int dest){
    int V = g.size();

    bool* visited = new bool[V + 1];
    for(int i = 0; i <= V; i++)
        visited[i] = false;

    bool result = dfs_path_directed(g, src, dest, visited);

    delete[] visited;
    return result;
}