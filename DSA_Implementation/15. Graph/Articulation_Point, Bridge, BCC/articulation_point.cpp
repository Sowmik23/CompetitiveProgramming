#include <bits/stdc++.h>
using namespace std;


///Time: O(V+E)  1 dfs running
///Memory: O(V)


vector<vector<int>> graph;


void dfs_visit(int x, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &ap){
	
	static int time = 0;
	int children = 0;
	
	visited[x] = true;
	disc[x] = low[x] = time++;
	
	for(auto i=graph[x].begin();i!=graph[x].end();i++){
		int y = *i;
		
		if(!visited[y]) {
			children++;
			parent[y] = x;
			dfs_visit(y, visited, disc, low, parent, ap);
			
			low[x] = min(low[x], low[y]);
			
			///if x is root
			if(parent[x]==-1 and children>1){
				ap[x] = true;
			}
			
			///if x is not root
			if(parent[x]!=-1 and low[y]>=disc[x]){
				ap[x] = true;
			}
		}
		else if(y!=parent[x]){
			low[x] = min(low[x], disc[y]);
		}
	}
}
		


void AP(int n){
	vector<bool> visited(n, false);
	vector<int> disc(n); ///discovery time
	vector<int> low(n);
	vector<int> parent(n, -1);

	vector<bool> ap(n, false);
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs_visit(i, visited, disc, low, parent, ap);
		}
	}
	
	///Now print the aprticulation points
	printf("Articulation points: ");
	for(int i=0;i<n;i++){
		if(ap[i]==true) cout<<i<<" ";
	}
	cout<<endl;
}


int main(){
	
	int nodes, edges, u, v;
	cin>>nodes>>edges;
	
	graph.assign(nodes, vector<int> ());
	
	while(edges--){
		cin>>u>>v;
		graph[u].push_back(v);
		//graph[v].push_back(u); //for undirected graph
	}
	
	
	AP(nodes);
	
	
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

Output: 0, 3
* */
