#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int dis[100005],b[100005];

struct st{
	int src,dest,cost;
}arr[100005];
	


int main()
{
	int test,n,m,c,d,mm,cst,q,value;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&arr[i].src,&arr[i].dest);
			c=b[arr[i].dest];
			d=b[arr[i].src];
			mm=c-d;
			cst=mm*mm*mm;
			arr[i].cost=cst;
		}
		
		for(int i=0;i<=n;i++) dis[i]=INF;
		
		dis[1]=0;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int u=arr[j].src;
				int v=arr[j].dest;
				int w=arr[j].cost;
				if(dis[v]>dis[u]+w and dis[u]!=INF)
				{
					dis[v]=dis[u]+w;
				}
			}
		}
		scanf("%d",&q);
		cout<<"Case "<<t<<":"<<endl;
		while(q--)
		{
			scanf("%d",&value);
			if(dis[value]>=INF or dis[value]<3) cout<<"?"<<endl;
			else cout<<dis[value]<<endl;
		}
		
	}
	
	return 0;
}
