#include<fstream>
#include"adj_list.h"
using namespace std;

void dfs_helper(Graph &g, int vertex, bool *visited){
	visited[vertex] = true;
	cout << vertex << ' ' ;
	Node* temp = g.getAdjList(vertex);
	while(temp){
		int nbr = temp->val;
		if(not visited[nbr]){
			dfs_helper(g, nbr, visited);
		}
		temp = temp->next;
	}
}
int connected_components(Graph &g){
	int ans = 0;
	int V = g.size();
	bool *visited = new bool[V+1];
	// memset(visited, false, sizeof(visited));
	for(int i = 0; i <= V; ++i){
		visited[i] = false;
	}
	for(int i = 1; i <= V; ++i){
		if(not visited[i]){
			dfs_helper(g, i, visited);
			ans++;
			cout << endl;
		}
	}
	return ans;
}

int main(){
	ifstream fin;
	fin.open("input.txt");
	int n;
	fin >> n;
	Graph g(n);
	int u, v;
	while(fin >> u >> v)
		g.addEdge(u, v);
	//graph is constructed now
	int cc = connected_components(g);
	cout << "the number of connected components is " << cc << '\n';

}