#include <bits/stdc++.h>
using namespace std;

vector<int>v1[110009];
vector<int>v1_reverse[110009];
vector<int>res;
int visited[110009];

void dfs_visit1(int i)
{
	visited[i]=1;
	int len=v1[i].size();
	for(int l=0;l<len;l++)
	{
		int k=v1[i][l];
		if(visited[k]==0)
		{
			dfs_visit1(k);
		}
	}
	res.push_back(i);
}

void dfs_visit2(int x,int p)
{
	visited[x]=1;
	int len=v1_reverse[x].size();
	for(int i=0;i<len;i++)
	{
		int k=v1_reverse[x][i];
		if(visited[k]==0)
		{
			dfs_visit2(k,p++);
		}
	}
	if(p) cout<<" ";
	cout<<x;
}

void DFS1(int n)
{
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			dfs_visit1(i);
		}
	}
}

void DFS2()
{
	int cnt=0;
	int ll=res.size();
	for(int i=ll-1;i>=0;i--)
	{
		if(visited[res[i]]==0)
		{
			cnt++;
			dfs_visit2(res[i],0);
			cout<<endl;
		}
	}
	cout<<"Total Number of SCC: "<<cnt<<endl;
}

int main()
{
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		v1[u].push_back(v);
		v1_reverse[v].push_back(u);
	}
	memset(visited,0,sizeof(visited));
	DFS1(n);
	memset(visited,0,sizeof(visited));
	DFS2();
	
	return 0;
}
