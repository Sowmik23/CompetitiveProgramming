#include<bits/stdc++.h>
using namespace std;
#define INF 100000
int dis[100005];
struct st
{
	int scr,des,weight;
};
int main()
{
	st ar[10005];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>ar[i].scr>>ar[i].des>>ar[i].weight;
	}
	for(int i=0;i<n;i++)
	{
		dis[i]=10000;
	}
	dis[0]=0;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{ 
			int u=ar[j].scr;
			int v=ar[j].des;
			int w=ar[j].weight;
			if(dis[v] > dis[u]+w and dis[u]!=10000)
			{
				dis[v]=dis[u]+w;
			}
		}
	}
	for(int j=0;j<m;j++)
	{
		int u=ar[j].scr;
		int v=ar[j].des;
		int w=ar[j].weight;
		if(dis[v] > dis[u]+w and dis[u]!=10000)
		{
			cout<<"Negative Weight cycle"<<endl;
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
