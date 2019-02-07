#include <bits/stdc++.h>
using namespace std;

int visited[205],v1[205][205],degree[205];
int n,m;

void dfs_visit(int i)
{
	visited[i]=0;
	for(int j=0;j<n;j++)
	{
		//cout<<j<<" j"<<endl;
		if(v1[i][j] && visited[j]==1) dfs_visit(j);
	}
}

int main()
{
	int u,v;
	while(scanf("%d%d",&n,&m)==2)
	{
		
		memset(degree,0,sizeof(degree));
		memset(visited,0,sizeof(visited));
		memset(v1,0,sizeof(v1));
		while(m--)
		{
			scanf("%d%d",&u,&v);
			v1[u][v]=1;
			v1[v][u]=1;
			degree[u]++;
			degree[v]++;
			visited[u]=visited[v]=1;
		}
		
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(degree[i]%2==1)
			{
				flag=1;
			}
		}
		if(flag==1) cout<<"Not Possible"<<endl;
		else 
		{
			int cnt=0;
			for(int i=0;i<n && cnt<=1;i++)
			{
				if(visited[i]==1)
				{
					//cout<<i<<endl;
					dfs_visit(i);
					cnt++;
				}
			}
			if(cnt==1) cout<<"Possible"<<endl;
			else cout<<"Not Possible"<<endl;
		}
	}
	
	return 0;
}
