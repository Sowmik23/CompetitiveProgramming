#include <bits/stdc++.h>
using namespace std;

vector<int>v1[1005];
int visited[1005],pre[1005],ap[1005],d[1005],low[1005];
int t;

void dfs_visit(int i)
{
	visited[i]=1;
	t=t+1;
	d[i]=low[i]=t;
	int child=0;
	int len=v1[i].size();
	for(int j=0;j<len;j++)
	{
		int k=v1[i][j];
		if(visited[k]==0)
		{
			child++;
			pre[k]=i;
			dfs_visit(k);
			low[i]=min(low[i],low[k]);
			if(pre[i]==-1 && child>1) ap[i]=1;
			if(pre[i]!=-1 && low[k]>=d[i]) ap[i]=1;
		}
		else if(k!=pre[i])
		{
			low[i]=min(low[i],d[k]);
		}
	}
}

void DFS(int n)
{
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			dfs_visit(i);
		}
	}
}

int main()
{
	int n,u,v;
	string str;
	while(cin>>n)
	{
		if(n==0) break;
		for(int i=0;i<=n;i++) v1[i].clear();
		while(getline(cin,str))
		{
			if(str=="0") break;
			//cout<<str<<endl;
			stringstream ss(str);
			ss>>u;
			//cout<<u<<endl;
			while(ss>>v)
			{
				//cout<<u<<" "<<v<<" ";
				v1[u].push_back(v);
				v1[v].push_back(u);
			}
		}
		memset(visited,0,sizeof(visited));
		memset(pre,-1,sizeof(pre));
		memset(ap,0,sizeof(ap));
		DFS(n);
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(ap[i]==1) cnt++;
		}
		cout<<cnt<<endl;
		
	}
	
	return 0;
}
