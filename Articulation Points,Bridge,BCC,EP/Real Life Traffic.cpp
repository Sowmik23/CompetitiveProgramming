#include <bits/stdc++.h>
using namespace std;

vector<int>v1[10005];
set<pair<int,int> >st;
pair<int,int>pa;
int visited[10005],low[10005],d[10005],pre[10005],identity[10005],ans[1005];
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
				if(i<k) pa=make_pair(i,k);
				else pa=make_pair(k,i);
				st.insert(pa);
			}
		}
		else if(k!=pre[i])
		{
			low[i]=min(low[i],d[k]);
		}
	}
}

void dfs_visit2(int i)
{
	visited[i]=1;
	identity[i]=cnt;
	int len=v1[i].size();
	for(int j=0;j<len;j++)
	{
		int k=v1[i][j];
		if(visited[k]==0)
		{
			if(i<k) pa={i,k};
			else pa={k,i};
			if(!st.count(pa)) dfs_visit2(k);
		}
	}
}

void DFS(int n)
{
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
	int test,n,m,u,v,ca=1;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		
		for(int i=0;i<=n;i++) v1[i].clear();
		st.clear();
		
		while(m--)
		{
			scanf("%d%d",&u,&v);
			v1[u].push_back(v);
			v1[v].push_back(u);
		}
		memset(visited,0,sizeof(visited));
		memset(pre,-1,sizeof(pre));
		t=0;
		DFS(n);
		
		memset(visited,0,sizeof(visited));
		memset(ans,0,sizeof(ans));
		memset(identity,0,sizeof(identity));
		cnt=0;
		for(int i=0;i<n;i++)
		{
			if(visited[i]==0)
			{
				cnt++;
				dfs_visit2(i);
			}
		}
		
		set<pair<int,int> >::iterator it;
		for(it=st.begin();it!=st.end();it++)
		{
			ans[identity[it->first]]++;
			ans[identity[it->second]]++;
		}
		int c=0;
		for(int i=1;i<=cnt;i++)
		{
			if(ans[i]==1) c++;
		}
		cout<<"Case "<<ca++<<": "<<(c+1)/2<<endl;
	}
		
	return 0;
}
