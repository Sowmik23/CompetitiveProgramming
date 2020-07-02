#include <bits/stdc++.h>
using namespace std;

vector<int>v1[100005];
vector<pair<int,int> >v2;
int visited[100005],pre[100005],low[100005],d[100005];
int t,cnt;

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
			if(low[k]>d[i])
			{
				if(i<k) v2.push_back({i,k});
				else v2.push_back({k,i});
			}
		}
		else if(k!=pre[i])
		{
			low[i]=min(low[i],d[k]);
		}
	}
}

void DFS(int  n)
{
	t=0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			dfs_visit(i);
		}
	}
}

int main()
{
	int t,n,m,u,v,Case=1;
    while((scanf("%d\n",&n)==1))
	{
		for(int i=0;i<=n;i++)
		{
			v1[i].clear();	
		}
		v2.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d ( %d )",&u,&m);

			for(int j=0;j<m;j++)
			{
				scanf("%d",&v);
			
				v1[u].push_back(v);
				v1[v].push_back(u);
			}
		}
		memset(visited,0,sizeof(visited));
		memset(pre,-1,sizeof(pre));
		
		DFS(n);
		//printf("Case %d:\n",Case++);
		int link=v2.size();
		printf("%d critical links\n",link);
		sort(v2.begin(),v2.end());
		for(int i=0;i<link;i++)
		{
			printf("%d - %d\n",v2[i].first,v2[i].second);
		}	
		cout<<endl;
		v2.clear();
	}
	
	return 0;
}
