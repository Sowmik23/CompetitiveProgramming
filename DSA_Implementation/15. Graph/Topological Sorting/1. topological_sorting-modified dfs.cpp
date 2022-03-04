#include <bits/stdc++.h>
using namespace std;

///Time: O(V+E)
///Memory: O(V) extra space for the stack 

//Topological Sorting for a graph is not possible 
//if the graph is not a DAG

//A DAG G has at least one vertex with in-degree 0 and one vertex 
//with out-degree 0

//a DAG does not contain a cycle

		
void addEdges(vector<vector<int>> &graph, int a, int b){
	graph[a].push_back(b);//as topological sort so graph must be directed
}


void dfs(int x, vector<vector<int>> &graph, vector<bool> &visited, stack<int> &stk){
	visited[x] = true;
	
	for(auto i=graph[x].begin();i!=graph[x].end();i++){
		if(!visited[*i]){
			dfs(*i, graph, visited, stk);
		}
	}
	stk.push(x);
}


void topological_sort(vector<vector<int>> &graph, int n){
	stack<int> stk;
	
	vector<bool> visited(n, false);
	
	for(int i=0;i<n;i++){
		if(visited[i]==false){
			dfs(i, graph, visited, stk);
		}
	}
	
	//print the vertices in topological sort order
	while(!stk.empty()){
		cout<<stk.top()<<" ";
		stk.pop();
	}
}


int main(){
	
	
	int n, e, u, v;
	cin>>n>>e;
	
	vector<vector<int>> graph(n, vector<int> ());
	
	for(int i=0;i<e;i++){
		cin>>u>>v;
		graph[u].push_back(v);
		//addEdges(graph, u, v);
	}
	
	topological_sort(graph, n);
	
	
	return 0;
}
/*
Input:
6 6
5 2 
5 0
4 0
4 1
2 3
3 1
* 		5		4
* 	  /	  \   /   \
* 	2		0		1
* 	   \	    /
* 			3	
* 
* 
Output: 4 5 2 0 3 1
*/
