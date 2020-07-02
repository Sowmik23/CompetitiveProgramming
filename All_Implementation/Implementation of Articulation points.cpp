#include <bits/stdc++.h>
using namespace std;

vector<int>v1[1000];
int visited[1000],pre[1000],d[1000],f[1000],low[1000];
int t;

void dfs_visit(int i)
{
	visited[i]=1;
	t=t+1;
	d[i]=low[i]=t;
	int len=v1[i].size();
	for(int j=0;j<len;j++)
	{
		int k=v1[i][j];
		if(visited[k]==0)
		{
			pre[k]=i;
			dfs_visit(k);
			if(low[k]>=d[i]) cout<<"Articulation point: "<<i<<endl;
			//if(low[k]>d[i]) cout<<"Bridge: "<<i<<" "<<k<<endl;
			if(low[k]<low[i]) low[i]=low[k];
		}
		else if(d[k]<low[i]) low[i]=d[k];
	}
	visited[i]=2;
	t=t+1;
	f[i]=t;	
}

void DFS(int n)
{
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			dfs_visit(i);
		}
	}
}

int main()
{
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		v1[u].push_back(v);
		v1[v].push_back(u);
	}
	memset(visited,0,sizeof(visited));
	memset(pre,0,sizeof(pre));
	memset(low,999999,sizeof(low));
	fill(d,d+1000,999999);
	fill(f,f+1000,999999);
	t=0;
	DFS(n);
	
	return 0;
}
