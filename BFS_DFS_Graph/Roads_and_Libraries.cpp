#include <bits/stdc++.h>
using namespace std;
vector<int>v1[100009];
int visited[100009];
int j;

int dfs_visit(int a)
{
	visited[a]=1;
	j++;
	int len=v1[a].size();
	for(int i=0;i<len;i++)
	{
		int k=v1[a][i];
		if(visited[k]==0)
		{
			dfs_visit(k);
		}
	}
	return (j-1);		
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,m,c_road,c_lib,u,v;
		cin>>n>>m>>c_lib>>c_road;
		memset(visited,0,sizeof(visited));
		
		while(m--)
		{
			cin>>u>>v;
			v1[u].push_back(v);
			v1[v].push_back(u);
		}
		long long int cnt=0,cn=0;
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==0)
			{
				j=0;
				cnt+=dfs_visit(i);
				cn++;
			}
		}
		long long int money=(cnt*c_road) + (cn*c_lib);
		long long int lib = (n*c_lib);
		long long int ans = min(money,lib);
		//if(t) cout<<endl;
		cout<<ans<<endl;
		
		for(int i=0;i<=n;i++) v1[i].clear();
	}
	
	return 0;
}
