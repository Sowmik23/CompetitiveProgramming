#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

vector<int>reverse_v1[100005];
vector<int>v2;
set<int>s;
int dis[100005],visited[100005];

struct st{
	int x,y,t;
} array;

vector<st> v1[10005];


void dfs_visit(int a)
{
	visited[a]=1;
	v2.push_back(a);
	for(int i=0;i<reverse_v1[a].size();i++)
	{
		int k=reverse_v1[a][i];
		if(visited[k]==0) 
		{
			dfs_visit(k);
		}
	}
}

int main()
{
	int test,n,m,u,v,w;
	scanf("%d",&test);
	for(int ii=1;ii<=test;ii++)
	{
	    
		scanf("%d%d",&n,&m);

		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			array.x=u;
			array.y=v;
			array.t=w;
			v1[i].push_back(array);
			reverse_v1[v].push_back(u);
		}
		for(int i=0;i<=n;i++)
		{
			dis[i]=INF;
		}
		
		dis[n]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				st use;
				int u=arr[j].x;
				int v=arr[j].y;
				int w=arr[j].t;
				if(dis[v]>dis[u]+w )
				{
					dis[v] = dis[u] + w;
				}
			}
		}
		
		int NegativeCycle=0;

		for(int j=1;j<=m;j++)
		{
			int u=arr[j].x;
			int v=arr[j].y;
			int w=arr[j].t;
			if(dis[v]>dis[u]+w)
			{
				NegativeCycle=1;
				s.insert(u);
				s.insert(v);
			}
		}
	
		cout<<"Case "<<ii<<": ";
		if(NegativeCycle==0) cout<<"impossible"<<endl;
		else 
		{
			memset(visited,0,sizeof(visited));
			set<int>::iterator it;
			for(it=s.begin();it!=s.end();it++)
			{
				if(visited[*it]==0) dfs_visit(*it);
			}
			sort(v2.begin(),v2.end());
			int l=0;
			for(int i=0;i<v2.size();i++) 
			{
			    if(l) cout<<" ";
				cout<<v2[i];
				l++;
			}
			cout<<endl;
		}
		for(int i=0;i<=n;i++) reverse_v1[i].clear();
		v2.clear();
		s.clear();
	}
	
	return 0;
}
