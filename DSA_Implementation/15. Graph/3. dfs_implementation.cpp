#include <bits/stdc++.h>
using namespace std;

///Usage:
/*Detecting cycle in graph
 * Finding path between two vertices
 * Topological Sorting
 * Bipartite or not
 * Finding Strongly Connected Components(SCC)
 * Solving mazes with only one solution
 */
 
 
///Time: O(V+E)
///Memory: O(V) 


vector<vector<int>> graph;
vector<bool>visited;


void addEdge(int u, int v){
	graph[u].push_back(v);
	graph[v].push_back(u); ///for undirected graph
}

void dfs_visit(int u){
	visited[u] = true;
	cout<<u<<" ";
	
	for(auto i = graph[u].begin();i!=graph[u].end();i++){
		if(visited[*i]==false){
			dfs_visit(*i);
		}
	}
} 
	
void dfs(int n){
	
	for(int i=0;i<n;i++){
		if(visited[i]==false){
			dfs_visit(i);
		}
	}
}



int main(){
	
	int nodes, edges, u, v;
	cin>>nodes>>edges;
	
	///initialization
	visited.assign(nodes, false);
	graph.assign(nodes, vector<int> ());
	
	for(int i=0;i<edges;i++){
		cin>>u>>v;
		addEdge(u, v);
	}
	
	dfs(nodes);
	
	
	return 0;
}
/*
Input:
5 7
0 1
0 4
1 2
1 3
1 4
2 3
3 4
Output: 0 1 2 3 4
*/
