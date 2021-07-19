#include <bits/stdc++.h>
using namespace std;

///Usage:
/*Detecting cycle in graph
 */
 
 
///Time: O(V+E)
///Memory: O(V) 


vector<vector<int>> graph;
vector<bool>visited;  //recursion Stack = recStack


void addEdge(int u, int v){
	graph[u].push_back(v);
	graph[v].push_back(u); ///for undirected graph
}

bool dfs_visit(int u, int parent){
	if(visited[u]==false) {
		visited[u] = true;
		
		//cout<<u<<" ";
		
		for(auto i = graph[u].begin();i!=graph[u].end();i++){
			if(!visited[*i] and dfs_visit(*i, u)){
				//dfs_visit(*i);
				return true;
			}
			else if(*i != parent) return true;
		}
	}
	return false;
} 
	
bool dfs(int n){
	
	for(int i=0;i<n;i++){
		if(dfs_visit(i, -1)) return true;
	}
	return false;
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
	
	if(dfs(nodes)==true) cout<<"contains cycle"<<endl;
	else cout<<"doesn't contain cycle"<<endl;
	
	return 0;
}
/*
Input:
4 6 
0 1
0 2
1 2 
2 0
2 3 
3 3
* output: contains cycle
* 
*
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
