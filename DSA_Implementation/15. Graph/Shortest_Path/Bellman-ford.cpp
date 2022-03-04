#include <bits/stdc++.h>
using namespace std;


///Time: O(EV)
///Memory: O(E);
/*
 * Dijkstra’s algorithm is a Greedy algorithm and time complexity 
 * is O(VLogV) (with the use of Fibonacci heap). Dijkstra doesn’t work 
 * for Graphs with negative weight edges, Bellman-Ford works for 
 * such graphs. Bellman-Ford is also simpler than Dijkstra and suites 
 * well for distributed systems. But time complexity of Bellman-Ford 
 * is O(VE), which is more than Dijkstra. 
 */



#define INF 100000

struct st {
	int src, des, weight;
};


int main()
{
	st arr[10005];
	
	int n,m;
	
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>arr[i].src>>arr[i].des>>arr[i].weight;
	}
	
	int dis[n];

	//memset(dis, INF, sizeof(dis));
	for(int i=0;i<n;i++){
		dis[i] = INF;
	}


	
	dis[0]=0;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{ 
			int u=arr[j].src;
			int v=arr[j].des;
			int w=arr[j].weight;
			
			if(dis[v] > dis[u]+w and dis[u]!=INF)
			{
				dis[v]=dis[u]+w;
			}
		}
	}
	
	for(int j=0;j<m;j++)
	{
		int u=arr[j].src;
		int v=arr[j].des;
		int w=arr[j].weight;
		
		if(dis[v] > dis[u]+w and dis[u]!=INF)
		{
			cout<<"Graph contains Negative Weight Cycle"<<endl;
			return 0;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<0<<"->"<<i<<" "<<dis[i]<<endl;
	}
	return 0;
}

/*
 * input: 

9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7 

output:
0->0 0
0->1 4
0->2 12
0->3 19
0->4 28
0->5 16
0->6 18
0->7 8
0->8 14


*/
