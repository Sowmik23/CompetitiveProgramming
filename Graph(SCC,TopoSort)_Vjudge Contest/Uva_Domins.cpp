#include <bits/stdc++.h>
using namespace std;
vector<int>v1[100009];
int visited[100009],res[100009],d[100009],f[100009];
int j,cnt,t=0;

void dfs_visit1(int a)
{
	t=t+1;
	d[a]=t;
	visited[a]=1;
	int len=v1[a].size();
	for(int i=0;i<len;i++)
	{
		int k=v1[a][i];
		if(visited[k]==0) dfs_visit1(k);
	}
	visited[a]=2;
	t=t+1;
	f[a]=t;
	res[j--]=a;
}

void dfs_visit2(int a)
{
	visited[a]=1;
	int len=v1[a].size();
	for(int i=0;i<len;i++)
	{
		int k=v1[a][i];
		if(visited[k]==0) dfs_visit2(k);
	}
}

void DFS1(int n)
{
	memset(visited,0,sizeof(visited));
	j=n;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			dfs_visit1(i);
		}
	}
}

void DFS2(int n)
{
	memset(visited,0,sizeof(visited));
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(visited[res[i]]==0)
		{
			cnt++;
			dfs_visit2(res[i]);
		}
	}
}

int main()
{
	int t,n,m,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++) v1[i].clear();
		while(m--)
		{
			scanf("%d%d",&x,&y);
			v1[x].push_back(y);
		}
		DFS1(n);
			for(int i=1;i<=n;i++) cout<<res[i]<<" ";
		cout<<endl;
		DFS2(n);
		cout<<cnt<<endl;
	}
	
	return 0;
}
