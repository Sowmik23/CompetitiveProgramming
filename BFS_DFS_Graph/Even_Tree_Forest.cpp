#include <bits/stdc++.h>
using namespace std;
vector<int>v1[101];
int visited[101];
int ans;

int dfs_visit(int a)
{
	visited[a]=1;
	int tmp=0;
	int num=0;
	int len=v1[a].size();
	for(int i=0;i<len;i++)
	{
		int k=v1[a][i];
		if(visited[k]==0)
		{
			tmp=dfs_visit(k);
			if(tmp%2==0) ans++;
			else num+=tmp;
		}
	}
	return num+1;
}
		
int DFS(int n)
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0) 
		{
			dfs_visit(i);
		}
	}
	return ans;
}

int main()
{
	int n,m,u,v;
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v;
		v1[u].push_back(v);
		v1[v].push_back(u);
	}
	memset(visited,0,sizeof(visited));
	cout<<DFS(n)<<endl;
	
	
	return 0;
}
