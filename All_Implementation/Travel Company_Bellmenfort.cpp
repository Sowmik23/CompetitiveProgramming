#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int dis[100005];

struct st{
	int src,dest,income,expences,cost;
}arr[100005];

int main()
{
	int test,n,m,p;
	scanf("%d",&test);
	for(int ii=1;ii<=test;ii++)
	{
		scanf("%d%d%d",&n,&m,&p);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d%d",&arr[i].src,&arr[i].dest,&arr[i].income,&arr[i].expences);
			arr[i].cost = p*arr[i].expences - arr[i].income;
		}
		
		for(int i=0;i<=n;i++) dis[i]=INF;
		
		dis[0]=0;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int u=arr[j].src;
				int v=arr[j].dest;
				int cst = arr[i].cost + dis[u];
				if(dis[v]>dis[u] + cst ) 
				{
					dis[v]=dis[u] + cst;
				}
			}
		}
		int hasNegativeCycle=0;
		
		for(int j=0;j<m;j++)
		{
			int u=arr[j].src;
			int v=arr[j].dest;
			int cst=arr[j].cost + dis[u];
			if(dis[v]>dis[u] + cst ) 
			{
				hasNegativeCycle = 1;
				break;
			}
		}
		cout<<"Case "<<ii;
		if(hasNegativeCycle==0) cout<<": NO";
		else cout<<": YES";
		cout<<endl;		
	}
	
	return 0;
}
