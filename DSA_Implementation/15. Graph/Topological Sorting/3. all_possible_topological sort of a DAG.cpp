#include <bits/stdc++.h>
using namespace std;

///Time: O(V+E)
///Memory: O(V)


void allPossible_top_sort(vector<vector<int>> &graph, vector<int> &indegree, int n, vector<int> &res, vector<int> &visited){
	
	int flag = false;
	for(int i=0;i<n;i++){
		if(indegree[i]==0 and !visited[i]){
			for(auto j=graph[i].begin();j!=graph[i].end();j++){
				indegree[*j]--;
			}
			
			///including in result
			res.push_back(i);
			visited[i] = true;
			allPossible_top_sort(graph, indegree, n, res, visited);
			
			///resetting all
			visited[i] = false;
			res.erase(res.end()-1);
			for(auto j = graph[i].begin();j!=graph[i].end();j++){
				indegree[*j]++;
			}
			
			flag = true;
		}
	}
	if(!flag) {
		for(int i=0;i<res.size();i++){
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
}


int main(){
	
	int nodes, edges, u, v;
	cin>>nodes>>edges;
	
	vector<vector<int>> graph(nodes, vector<int> ());
	vector<int> indegree(nodes, 0);
	
	for(int i=0;i<edges;i++){
		cin>>u>>v;
		graph[u].push_back(v);
		indegree[v]++;
	}
	
	vector<int> res, visited(nodes, false);
	allPossible_top_sort(graph, indegree, nodes, res, visited);
	

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
