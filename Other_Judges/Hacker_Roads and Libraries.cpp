#include <bits/stdc++.h>
using namespace std;
vector<int>v1[100009];
int visited[100009];
int j;

int dfs_visit(int x)
{
	j++;
	visited[x]=1;
	int len=v1[x].size();
	for(int i=0;i<len;i++)
	{
		int k=v1[x][i];
		if(visited[k]==0)
		{
			 visited[k]=1;
			 dfs_visit(k);
		 }
	}
	return j-1;
}

int main()
{
	int t,u,v;
	long long int n,m,c_lib,c_road;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&c_lib,&c_road);
		for(int i=0;i<=n;i++) v1[i].clear();
		while(m--)
		{
			scanf("%d%d",&u,&v);
			v1[u].push_back(v);
			v1[v].push_back(u);
		}
		memset(visited,0,sizeof(visited));
		int cn=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			j=0;
			if(visited[i]==0)
			{
				cn+=dfs_visit(i);
				cnt++;
			}
		}
		long long int total=cn*c_road + cnt*c_lib;
		long long int t_lib=n*c_lib;
		cout<<min(total,t_lib)<<endl;
	}
	
	
	return 0;
}
