#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> graph;
vector<bool> visited;


void dfs_visit(int u){
	visited[u]= true;
	recStack[u] = true;
	
	for(auto i: graph[u]){
		if(!visited[i]) dfs_visit(i);
		
		if()
	}
	
	recStack[u] = false;
}


void dfs(int n){
	int cnt=0;
	for(int i=0;i<n;i++){
		
		if(visited[i]==false){
			dfs_visit(i);
			cnt++;
		}
	}
	
	cout<<cnt<<endl;
}


int main(){
	
	int n, m, u, v;
	cin>>n>>m;
	
	visited.assign(n, false);
	
	dfs(n);
	
	
	return 0;
}
