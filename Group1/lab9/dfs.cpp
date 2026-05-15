#include<iostream>
#include"graph.h"
using namespace std;
void dfsHelper(Graph &g, const int vertex, bool *visited){
	visited[vertex] = true;
	cout << vertex << ' ';
	list *temp = g.adj[vertex];
	while(temp){
		if(not visited[temp->val]){
			dfsHelper(g, temp->val, visited);
		}
		temp = temp->next;
	}
}
void DFS(Graph &g, const int start){
	int n = g.size();
	bool *visited = new bool[n + 1];
	for(int i = 0; i <= n; ++i)
		visited[i] = false;
	for(int i = start; i <= n; ++i){
		if(not visited[i]){
			dfsHelper(g, i, visited);
			cout << '\n';
		}
	}
}