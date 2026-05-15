#ifndef GRAPH_H
#define GRAPH_H

struct list{
	int val;
	list *next;
	list(const int value): val(value), next(nullptr){}
};

class Graph{
public:
	int V;
	list **adj;
	Graph(const int n){
		V = n;
		adj = new list*[n + 1];
		for(int i = 0; i <= n; ++i)
			adj[i] = nullptr;
	}
	int size(){
		return V;
	}
	void addEdge(const int u, const int v){
		list *temp = adj[u];
		while(temp){
			if(temp->val == v)
				return;
			temp = temp->next;
		}
		list *n1 = new list(v), *n2 = new list(u);
		n1->next = adj[u]; adj[u] = n1;
		n2->next = adj[v]; adj[v] = n2;
	}
	void addDirectedEdge(const int u, const int v){
		list *temp = new list(v);
		temp->next = adj[u];
		adj[u] = temp;
	}
};

void DFS(Graph &g, const int start);
void dfsHelper(Graph &g, const int vertex, bool *visited);

#endif