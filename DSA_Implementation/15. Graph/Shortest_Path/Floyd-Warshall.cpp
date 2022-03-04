#include <bits/stdc++.h>
using namespace std;

///Time : O(V^3)
///Memory: O(n^2)


/* The Floyd Warshall Algorithm is for solving the All Pairs 
 * Shortest Path problem. The problem is to find shortest distances 
 * between every pair of vertices in a given edge weighted directed 
 * Graph. 
 */

#define INF 99999


int adjMatrix[100][100], parent[100][100];

void initialize(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
			parent[i][j] = i;
			if(i==j) adjMatrix[i][j] = 0;
			else adjMatrix[i][j] = INF;
		}
	}
}

void printPath(int src, int dst){
	if(src==dst){
		cout<<"Path: "<<src;
		return ;
	}
	printPath(src, parent[src][dst]);
	cout<<" "<<dst;
}


int main(){
	
	int n, m, u, v, w;
	cin>>n>>m;
	
	initialize(n);
	
	while(m--){
		cin>>u>>v>>w;
		adjMatrix[u][v] = w;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j]){
					adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
					parent[i][j] = parent[k][j];
				}
			}
		}
	}
	
	int source, destination;
	cout<<"Enter source node and destination node"<<endl;
	cin>>source>>destination;
	
	cout<<"Distance: "<<adjMatrix[source][destination]<<endl;
	
	printPath(source, destination);
	
	
	
	return 0;
}


/*
Input:
5 9 
1 2 2
1 3 1
1 5 3
2 4 4 
3 2 1
3 5 1
4 1 1
4 3 3
4 5 5

1 4
Output:
Distance: 6
Path: 1 2 4
*/
