#include <bits/stdc++.h>
using namespace std;



///Tarjan's algorithm
///Time: O(V+E)  1 dfs running
///Memory: O(V)


vector<vector<int>> graph;

void dfs_visit(int x, vector<int> &disc, vector<int> &low, stack<int> &stk, vector<bool> &stackMember){
	
	static int time = 0;
	
	disc[x] = low[x] = time++;
	
	stk.push(x);
	stackMember[x] = true;
	
	for(auto i=graph[x].begin(); i!=graph[x].end();i++){
		int y = *i;
		
		if(disc[y]==-1) {
			dfs_visit(y, disc, low, stk, stackMember);
			low[x] = min(low[x], low[y]);
		}
		else if(stackMember[y]==true){
			low[x] = min(low[x], disc[y]);
		}
	}
	
	
	int f = 0;
	if(low[x]==disc[x]){
		while(stk.top()!=x){
			f = stk.top();
			
			cout<<f<<" ";
			
			stackMember[f] = false;
			stk.pop();
		}
		f = stk.top();
		
		cout<<f<<" "<<"\n";
		stackMember[f] = false;
		stk.pop();
	}
}


void SCC(int n){
	
	vector<int> disc(n, -1); //initialize with -1
	vector<int> low(n, -1);
	vector<bool> stackMember(n, false);

	stack<int> stk;
	
	for(int i=0;i<n;i++){
		if(disc[i]==-1){
			dfs_visit(i, disc, low, stk, stackMember);
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
	}
	
	
	SCC(nodes);
	
	
	
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
Total : 3
0 1 2
3 
4
*/
