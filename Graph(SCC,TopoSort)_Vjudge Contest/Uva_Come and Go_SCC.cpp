#include <bits/stdc++.h>
using namespace std;

vector<int>v1[2009];
int cnt,visited[2009],low[2009],num[2009];

int IsInOneSCC(int a)
{
	num[a]=cnt++;
	low[a]=num[a];
	
	visited[a]=1;
	int len=v1[a].size();
	for(int i=0;i<len;i++)
	{
		int k=v1[a][i];
		if(num[k]==-1)
		{
			if(!IsInOneSCC(k)) return 0;
		}
		if(visited[k]) low[a]=min(low[a],low[k]);
	}
	if(low[a]==num[a] && a!=1) return 0;
	return 1;
}

int all_visited(int n)
{
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0) return 0;
	}
	return 1;
}

int main()
{
	int n,m,u,v,p;
	while(scanf("%d%d",&n,&m))
	{
		if(n==0 && m==0) break;
		for(int i=0;i<=n;i++)
		{
			v1[i].clear();
			num[i]=-1;
		}
		memset(visited,0,sizeof(visited));
		
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&p);
			v1[u].push_back(v);
			if(p==2)  v1[v].push_back(u);
		}
		
		cnt=0;
		int c=IsInOneSCC(1);
		int d=all_visited(n);
		
		if(c && d) cout<<"1"<<endl;
		else cout<<"0"<<endl;
	}
	
	return 0;
}
