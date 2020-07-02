#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> >v1[109];
int dis[1005],parent[1005];

void bfs(int x)
{
	priority_queue<pair<int,int> , vector<pair<int,int> >,greater<pair<int,int> > > pq;  //ekhane priority_queue eivabei korte hoy....//
	pq.push({x,0});
	dis[x]=0;
	while(!pq.empty())
	{
		int u=pq.top().first;
		pq.pop();
		vector<pair<int,int> >::iterator it;
		for(it=v1[u].begin();it!=v1[u].end();it++)
		{
			int v=it->first;
			int w=it->second;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				pq.push({v,dis[v]});
				parent[v]=u;
			}
		}
	}
}
	
int main()
{
	int test,source,destination,weight,n,e,t,m;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&n,&e,&t);
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&source,&destination,&weight);
			v1[destination].push_back({source,weight});
		}
		//memset(dis,t+10,sizeof(dis));  //eita korele wrong khabe....//
		for(int i=1;i<=n;i++) dis[i]=t+10;
		bfs(e);
		int mices=0;
		for(int i=1;i<=n;i++)
		{
			if(dis[i]<=t) 
			{
				mices++;
			}
		}
		cout<<mices<<endl;
		for(int i=1;i<=n;i++) v1[i].clear();
		if(test) puts("");
	}
	
	return 0;
}
