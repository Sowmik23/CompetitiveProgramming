#include <bits/stdc++.h>
using namespace std;
vector<int>v1[50009];
int visited[50009],length[50009];

int dfs_visit(int d)
{
	visited[d]=1;
	int len=0;
	int l=v1[d].size();
	for(int i=0;i<l;i++)
	{
		int k=v1[d][i];
		if(visited[k]==0)
		{
			len += dfs_visit(k) +1;
		}
	}
	visited[d]=0;
	return length[d]=len;
}
	
int main()
{
	int t,c=1;
	cin>>t;
	while(t--)
	{
		int n,u,v;
		scanf("%d",&n);
		memset(visited,0,sizeof(visited));
		memset(length,0,sizeof(length));
		int m=n;
		while(m--)
		{
			scanf("%d%d",&u,&v);
			v1[u].push_back(v);
		}
		int mx=-100,x;
		for(int i=1;i<=n;i++)
		{
			if(length[i]==0)
			{
				dfs_visit(i);
			}
			if(length[i]>mx)
			{
				mx=length[i];
				x=i;
			}
		}
		printf("Case %d: %d\n",c++,x);
		for(int i=0;i<=n;i++) v1[i].clear();		
		
	}
	
	return 0;
}
