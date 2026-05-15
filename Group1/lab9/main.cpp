#include"graph.h"
#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream fin("input.txt");
	int n;
	fin >> n;
	int u, v;
	Graph g(n);
	while(fin >> u >> v){
		g.addEdge(u, v);
	}
	DFS(g, 1);

}