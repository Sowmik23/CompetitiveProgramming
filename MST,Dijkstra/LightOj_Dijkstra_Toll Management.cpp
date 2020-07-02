#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> >v1[100005];
vector<pair<int,int> >reverse_v1[100005];
long long int dis[1000005],reverse_dis[1000005];

void Dijkstra(int s)
{
	priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	pq.push({s,0});
	dis[s]=0;
	while(!pq.empty())
	{
		int u=pq.top().first;
		pq.pop();
		vector<pair<int,int> >::iterator it;
		for(it=v1[u].begin();it!=v1[u].end();it++)
		{
			int v=it->first;
			int weight=it->second;
			if(dis[v]>dis[u]+weight)
			{
				dis[v]=dis[u]+weight;
				pq.push({v,dis[v]});
			}
		}
	}
}

void reverse_Dijkstra(int t)
{
	priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	pq.push({t,0});
	reverse_dis[t]=0;
	while(!pq.empty())
	{
		int u=pq.top().first;
		pq.pop();
		vector<pair<int,int> >::iterator it;
		for(it=reverse_v1[u].begin();it!=reverse_v1[u].end();it++)
		{
			int v=it->first;
			int weight=it->second;
			if(reverse_dis[v]>reverse_dis[u]+weight)
			{
				reverse_dis[v]=reverse_dis[u]+weight;
				pq.push({v,reverse_dis[v]});
			}
		}
	}
}

int main()
{
	int test,n,m,s,t,cost_limit,u,v,c;
	scanf("%d",&test);
	for(int tt=1;tt<=test;tt++)
	{
		scanf("%d%d%d%d%d",&n,&m,&s,&t,&cost_limit); 
														/* n=node 
														 * m=edge
														 * s=source
														 * t=destination
														 * p=cost_limit
														 */
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&c);
			v1[u].push_back({v,c});
			reverse_v1[v].push_back({u,c});
		}
		for(int i=0;i<=n;i++)
		{
			dis[i]=999999;
			reverse_dis[i]=999999;
		}
		
		Dijkstra(s);
		reverse_Dijkstra(t);
		
		long long int ans=-1;
		for(int i=1;i<=n;i++)
		{
			vector<pair<int,int> >::iterator it;
			for(it=v1[i].begin();it!=v1[i].end();it++)
			{
				int node=it->first;
				int weight=it->second;
				if(weight+dis[i]+reverse_dis[node]<=cost_limit and weight>ans)
				{
					ans=weight;
				}
			}
		}
		printf("Case %d: %lld\n",tt,ans);
		
		for(int i=1;i<=n;i++)
		{
			v1[i].clear();
			reverse_v1[i].clear();
		}
	}

	return 0;
}

