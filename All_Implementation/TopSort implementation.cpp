#include <bits/stdc++.h>
using namespace std;

vector<int>v1[110009];
int visited[110009],res[110009];
int j;

void dfs_visit(int x)
{
	visited[x]=1;
	int len=v1[x].size();
	for(int l=0;l<len;l++)
	{
		int k=v1[x][l];
		if(visited[k]==0)
		{
			dfs_visit(k);
		}
	}
	res[j--]=x;
}

int main()
{
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		v1[u].push_back(v);
	}
	
	memset(visited,0,sizeof(visited));
	
	j=n-1;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			dfs_visit(i);
		}
	}
	
	for(int i=0;i<n;i++)
	{
		//if(i) cout<<" ";
		cout<<res[i]<<endl;
	}
	//cout<<endl;
	
	return 0;
}
