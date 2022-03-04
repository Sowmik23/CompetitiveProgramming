#include <bits/stdc++.h>
using namespace std;


///Time: O(V+E)  1 dfs running
///Memory: O(V)


vector<vector<int>> graph;


void dfs_visit(int x, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent){
	
	static int time = 0;
	
	visited[x] = true;
	disc[x] = low[x] = time++;
	
	for(auto i=graph[x].begin();i!=graph[x].end();i++){
		int y = *i;
		
		if(!visited[y]){
			parent[y] = x;
			dfs_visit(y, visited, disc, low, parent);
			
			low[x] = min(low[x], low[y]);
			
			//if lowest vertex reachable from subtree under y is below
			//x	in dfs tree, then x-y is a bridge.
			if(low[y]>disc[x]){
				cout<<x<<" "<<y<<endl;
			}
		}
		else if(y!=parent[x]){
			low[x] = min(low[x], disc[y]);
		}
	}
}


void bridge(int n){
	
	vector<bool> visited(n, false);
	vector<int> disc(n);
	vector<int> low(n);
	vector<int> parent(n, -1);
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs_visit(i, visited, disc, low, parent);
		}
	}
}



int main(){
	
	int nodes, edges, u, v;
	cin>>nodes>>edges;
	
	graph.assign(nodes, vector<int> ());
	
	while(edges--){
		cin>>u>>v;
		graph[u].push_back(v);
		///graph[v].push_back(u); //if graph is undirected
	}
	
	
	bridge(nodes);
	
	
	return 0;
}
/*
Input:
5 5
1 0
0 2
2 1
0 3
3 4

Output: 
3 4
0 3
* */
