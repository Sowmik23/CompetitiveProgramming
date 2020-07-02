#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> >v1[99999];
int dis[99999];


void bfs(int x)
{
	priority_queue<int ,vector<int>,greater<int> >pq;
	pq.push(x);
	dis[x]=0;
	while(!pq.empty())
	{
		int x=pq.top();
		pq.pop();
		vector<pair<int,int> >::iterator it;
		for(it=v1[x].begin();it!=v1[x].end();it++)
		{
			int y=it->first;
			int z=it->second;
			if(dis[y]>dis[x]+z)
			{
				dis[y]=dis[x]+z;
				pq.push(y);
			}
		}
	}
}

int main()
{
	int test,Case=1,n,m,s,t,u,v,w;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d%d",&n,&m,&s,&t);
	
		
		//v1=new vector<pair<int,int> >[9999];
		
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			v1[u].push_back({v,w});
			v1[v].push_back({u,w});
		}
	    for(int i=0;i<=n;i++) dis[i]=999999;
	    
		bfs(s);
		
		if(dis[t]==999999) cout<<"Case #"<<Case++<<": "<<"unreachable"<<endl;
		else cout<<"Case #"<<Case++<<": "<<dis[t]<<endl;
		for(int i=0;i<n;i++) v1[i].clear();
	}
	
	return 0;
}
