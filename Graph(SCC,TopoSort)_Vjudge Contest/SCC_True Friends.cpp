#include <bits/stdc++.h>
using namespace std;
vector<int>v1[105];
vector<int>v1_reverse[105];
char known[105][105];
int j,cnt,t,d[105],f[105],transpose[105],visited[105];

void dfs_visit1(int a)
{
	t=t+1;
	d[a]=t;
	visited[a]=1;
	int l=v1[a].size();
	for(int i=0;i<l;i++)
	{
		int k=v1[a][i];
		if(visited[k]==0) dfs_visit1(k);
	}
	t=t+1;
	f[a]=t;
	transpose[j--]=a;
}

void dfs_visit2(int a)
{
	visited[a]=1;
	int l=v1_reverse[a].size();
	for(int i=0;i<l;i++)
	{
		int k=v1_reverse[a][i];
		if(visited[k]==0) dfs_visit2(k);
	}
}

void DFS1(int n)
{
	memset(visited,0,sizeof(visited));
	j=n;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0) dfs_visit1(i);
	}
}

void DFS2(int n)
{
	memset(visited,0,sizeof(visited));
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(visited[transpose[i]]==0)
		{
			cnt++;
			dfs_visit2(transpose[i]);
		}
	}
}

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++) 
		{
			v1[i].clear();
			v1_reverse[i].clear();
		}
		for(int i=0;i<n;i++)
		{
			cin>>known[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(known[i][j]=='Y') 
				{
					v1[i+1].push_back(j+1);
					v1_reverse[j+1].push_back(i+1);
				}
			}
		}
		DFS1(n);
		DFS2(n);
		cout<<cnt<<endl;
	}
	
	return 0;
}
