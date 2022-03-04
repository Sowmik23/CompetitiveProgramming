#include <bits/stdc++.h>
using namespace std;


/// A directed graph is strongly connected if there is a path between 
/// all pairs of vertices. A strongly connected component (SCC) 
/// of a directed graph is a maximal strongly connected subgraph



///Kosaraju's algorithm
///Time: O(V+E)  2 dfs running
///Memory: O(V)

vector<vector<int>> graph;
vector<vector<int>> reversedGraph;
vector<bool> visited;

void dfs_visit(int x, stack<int> &stk){
	visited[x] = true;
	
	for(auto i=graph[x].begin();i!=graph[x].end();i++){
		if(!visited[*i]){
			dfs_visit(*i, stk);
		}
	}
	stk.push(x);
}


void dfs_visit2(int val){
	visited[val] = false;
	
	cout<<val<<" ";
	
	for(auto i=reversedGraph[val].begin();i!=reversedGraph[val].end();i++){
		if(visited[*i]==true){
			dfs_visit2(*i);
		}
	}
}


void printSCC(int n){
	stack<int> stk;
	
	visited.assign(n, false);
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs_visit(i, stk);
		}
	}
	
	
	//visited.assign(n, false);

	
	int cnt = 0;
	while(!stk.empty()){
		int top = stk.top();
		stk.pop();
		
		if(visited[top]==true){
			//cout<<top<<endl;
			dfs_visit2(top);
			cout<<endl;
			cnt++;
		}
	}
	cout<<"Total number of strongly connected components: "<<cnt<<endl;
}


int main(){
	
	int nodes, edges, u, v;
	cin>>nodes>>edges;
	
	///vector<vector<int>> graph(nodes, vector<int> ());
	///vector<vector<int>> reversedGraph(nodes, vector<int> ());
	
	graph.assign(nodes, vector<int> ());
	reversedGraph.assign(nodes, vector<int> ());
	
	while(edges--){
		cin>>u>>v;
		graph[u].push_back(v);
		reversedGraph[v].push_back(u);
	}


	printSCC(nodes);
	
	
	
	return 0;
}
/*
Input:
1 0
0 2
2 1
0 3
3 4

Output:
Total : 3
0 1 2
3 
4
*/

