#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n,m,dis[100005],pre[100005];

struct st{
	int src,dest,time;
}arr[100005];

int Bellmenfort(int src)
{
	dis[src]=0;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int u=arr[j].src;
			int v=arr[j].dest;
			int w=arr[j].time;
			if(dis[v]>dis[u]+w and dis[u]!=INF)
			{
				dis[v]=dis[u]+w;
				pre[v]=u;
			}
		}
	}
	for(int j=0;j<m;j++)
	{
		int u=arr[j].src;
		int v=arr[j].dest;
		int w=arr[j].time;
		if(dis[v]>dis[u]+w and dis[u]!=INF)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&arr[i].src,&arr[i].dest,&arr[i].time);
		}
		for(int i=0;i<=n;i++)
		{
			dis[i]=INF;
			pre[i]=-1;
		}
		
		if(Bellmenfort(0)) cout<<"not possible"<<endl;
		else cout<<"possible"<<endl;
	}
	
	return 0;
}
