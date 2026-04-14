#include "adj_list.h"
#include<queue>
using namespace std;

bool BipartiteCheck(Graph &g, int *color, int start){
	queue<int> q;
	q.push(start);
	color[start] = 0;

	while(not q.empty()){
		int curr = q.front();
		q.pop();
		Node *temp = g.getAdjList(curr);
		while(temp){
			int nbr = temp->val;
			if(color[nbr] == -1){
				color[nbr] = 1 - color[curr];
				q.push(nbr);
			}
			else if(color[nbr] == color[curr])
				return false;
			temp = temp->next;
		}
	}
	return true;
}

int main(){
	Graph g(3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	int *color;
	color = new int[g.size() + 1];
	for(int i = 0; i <= g.size(); ++i)
		color[i] = -1;

	bool flag = true;

	for(int i = 1; i <= g.size(); ++i){
	    if(color[i] == -1){
	        if(!BipartiteCheck(g, color, i)){
	            flag = false;
	            break;
	        }
	    }
	}
	(flag)? cout << "the given graph is bipartite\n" : cout << "the given graph is not bipartite\n";
	delete[] color;
}