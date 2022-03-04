#include <bits/stdc++.h>
using namespace std;

///Time: O(V+E)
///Memory: O(V) extra space for the stack 

//Topological Sorting for a graph is not possible 
//if the graph is not a DAG

//A DAG G has at least one vertex with in-degree 0 and one vertex 
//with out-degree 0

//a DAG does not contain a cycle

///Kahn's algorithm: counting indegree


void topological_sort(vector<vector<int>> &graph, int n){
	
	///create a vector to store indegrees of all vertices.
	vector<int> indegree(n);
	
	for(int i=0;i<n;i++){
		for(auto j=graph[i].begin();j!=graph[i].end();j++){
			indegree[*j]++;
		}
	}
	
	///create an queue  to enqueue all vertices with indegree 0'
	queue<int> q;
	for(int i=0;i<n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	
	vector<int> top_ordered;
	int cnt =0;
	
	while(!q.empty()){
		int f = q.front();
		q.pop();
		
		top_ordered.push_back(f);
		
		for(auto i=graph[f].begin();i!=graph[f].end();i++){
			if(--indegree[*i]==0){
				q.push(*i);
			}
		}
		cnt++;
	}
	if(cnt!=n){
		cout<<"There exists a cycle in the graph\n";
		return ;
	}
	
	//print the ordered list
	for(auto i: top_ordered){
		cout<<i<<" ";
	}
	cout<<endl;
}

int main(){
	
	int nodes, edges, u, v;
	cin>>nodes>>edges;
	
	vector<vector<int>> graph(nodes, vector<int> ());
	
	for(int i=0;i<edges;i++){
		cin>>u>>v;
		graph[u].push_back(v); ///we can also compute indegree here
		//indegree[v]++;
	}
	
	topological_sort(graph, nodes);
	
	
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
