/*Theory:***
Some Instruction's: 
* 
Dijkstra: Shortest path from one node to all nodes.
* 
Bellman-Fort: Shortest path from one node to all nodes,negative edges allowed.
* 
Flyod-Warshall: Shortest path between all pair of vertices,negative edges allowed.
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 99999

int AdjMatrix[100][100],parent[100][100];

void initialize(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			parent[i][j]=i;
			if(i==j) AdjMatrix[i][j]=0;
			else AdjMatrix[i][j]=99999;
		}
	}
}

void printpath(int src,int dst)
{
	if(src==dst) 
	{
		cout<<"Path: "<<src;
		return ;
	}
	printpath(src,parent[src][dst]);
	cout<<" "<<dst;
}

int main()
{
	int n,m,u,v,cost;
	scanf("%d%d",&n,&m);
	initialize(n);
	
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&cost);
		AdjMatrix[u][v]=cost;
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(AdjMatrix[i][j] > AdjMatrix[i][k] + AdjMatrix[k][j])
				{
					AdjMatrix[i][j] = AdjMatrix[i][k] + AdjMatrix[k][j];
					parent[i][j] = parent[k][j];
				}
			}
		}
	}
	
	int source,destination;
	cout<<"Enter source & destination: "<<endl;
	scanf("%d%d",&source,&destination);
	
	cout<<"Distance: "<<AdjMatrix[source][destination]<<endl;
	
	printpath(source,destination);
	
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
