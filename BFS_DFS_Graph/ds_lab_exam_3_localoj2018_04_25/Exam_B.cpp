#include<bits/stdc++.h>
using namespace std;
int t,c,d[10000],f[10000],visited[10000],cnt[10000];
vector<int> v1[10000];

void dfs_visit(int i,int c)
{
	t=t+1;
	d[i]=t;
	cnt[i]=c;
	vector<int>::iterator it;
	for(it=v1[i].begin();it!=v1[i].end();it++)
	{
		if(visited[*it]==0)
		{
			visited[*it]=1;
			cnt[*it]=c;
			dfs_visit(*it,c);
		}
	}
	t=t+1;
	f[i]=t;	
}

int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	memset(visited,0,sizeof(visited));
	memset(cnt,0,sizeof(cnt));
	
	while(m--)
	{
		scanf("%d%d",&x,&y);
		v1[x].push_back(y);
		v1[y].push_back(x);
	}
	c=1;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			dfs_visit(i,c);
			c++;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<i<<": "<<cnt[i]<<endl;
	}
	
	return 0;
}

