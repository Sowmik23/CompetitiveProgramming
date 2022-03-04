#include <bits/stdc++.h>
using namespace std;


///Time: O(V+E)  1 dfs running
///Memory: O(V)


/* A graph is BCC
 * iff
 * 1) The graph is connected. 
 * 2) There is not articulation point in graph.
 * */


vector<vector<int>> graph;


bool dfs_visit(int x, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent){
	static int time = 0;
	
	int children = 0;
	
	visited[x] = true;
	disc[x] = low[x] = time++;
	
	for(auto i=graph[x].begin();i!=graph[x].end();i++){
		int y = *i;
		if(!visited[y]){
			children++;
			parent[y] = x;
			if(dfs_visit(y, visited, disc, low, parent)) return true;
			
			low[x] = min(low[x], low[y]);
			if(parent[x]==-1 and children>1) return true;
			
			if(parent[x]!=-1 and low[y]>disc[x]) return true;
		}
		else if(y!=parent[x]) {
			low[x] = min(low[x], disc[y]);
		}
	}
	return false;
}



bool BCC(int n){
	vector<bool> visited(n, false);
	vector<int> disc(n);
	vector<int> low(n);
	vector<int> parent(n, -1);
	
	bool d = dfs_visit(0, visited, disc, low, parent);
	if(d==true) return false;
	
	for(int i=0;i<n;i++){
		if(visited[i]==false) return false;
	}
	
	return true;
}


int main(){
		
	int nodes, edges, u, v;
	cin>>nodes>>edges;
	
	graph.assign(nodes, vector<int> ());
	
	while(edges--){
		cin>>u>>v;
		graph[u].push_back(v);
	}
	
	bool res = BCC(nodes);
	
	if(res==true) cout<<"Given graph is Biconnected"<<endl;
	else cout<<"Given graph is not Biconnected"<<endl;
	
	
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

Output: No
* 
Input
3 3
0 1
1 2
2 0
Output: YES
* */
