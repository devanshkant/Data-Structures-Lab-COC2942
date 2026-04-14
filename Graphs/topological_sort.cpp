#include"adj_list.h"
#include<fstream>
#include<queue>
using namespace std;

void kahn_algorithm(int inDegree[], Graph &g){
    queue<int> q;
    int V = g.size();

    for(int i = 1; i <= V; ++i)
        if(inDegree[i] == 0)
            q.push(i);

    int count = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        cout << curr << ' ';
        count++;

        auto temp = g.getAdjList(curr);

        while(temp){
            int nbr = temp->val;
            inDegree[nbr]--;

            if(inDegree[nbr] == 0)
                q.push(nbr);

            temp = temp->next;
        }
    }

    if(count < V)
        cout << "\nCycle detected (Not a DAG)\n";
}

int main(){
	int n;
	ifstream fin;
	fin.open("input.txt");
	fin >> n;
	Graph g(n);
	int u, v;
	while(fin >> u >> v){
		g.addDirectedEdge(u, v);
	}
	int* inDegree = new int[n+1];
	for(int i = 0; i <= n; ++i)
		inDegree[i] = 0;
	for(int i = 1; i <= n; ++i){
		auto list = g.getAdjList(i);
		while(list){
			inDegree[list->val]++;
			list = list->next;
		}
	}
	kahn_algorithm(inDegree, g);
	delete[] inDegree;
}