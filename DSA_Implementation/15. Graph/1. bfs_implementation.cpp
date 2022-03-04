#include <bits/stdc++.h>
using namespace std;

///Time: O(V+E)
///Memory: O(V) 

vector<bool> visited;
vector<vector<int>> v;

void edge(int a, int b){
	v[a].push_back(b);
	///for undirected graph also add v[b].push_back(a);
}


void bfs(int x){
	queue<int> q;
	q.push(x);
	visited[x] = true;
	
	while(!q.empty()){
		int f = q.front();
		q.pop();
		cout<<f<<" ";
		
		for(auto i = v[f].begin();i!=v[f].end();i++){
			if(!visited[*i]){
				q.push(*i);
				visited[*i] = true;
			}
		}
	}
}


int main(){
	
	int nodes, edges;
	
	cin>>nodes>>edges;
	
	visited.assign(nodes, false);
	v.assign(nodes, vector<int>());
	
	int a, b;
	for(int i=0;i<edges;i++){
		cin>>a>>b;
		edge(a, b);
	}
	
	/*
	///print the graph
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	
	///run bfs
	for(int i=0;i<nodes;i++){
		if(!visited[i]) bfs(i);
	}
	
	
	return 0;
}
/*
Test case:
8 10
0 1
0 2
0 3
0 4
1 5
2 5
3 6
4 6
5 7
6 7
output: 0 1 2 3 4 5 6 7 
*/
