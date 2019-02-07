#include <bits/stdc++.h>
using namespace std;

vector<int>v1[1005];
pair<int,int> pa;
set<pair<int,int> >st;
int visited[1005],low[1005],pre[1005],d[1005];
int t;

void dfs_visit(int i)
{
	visited[i]=1;
	t=t+1;
	low[i]=d[i]=t;
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
				printf("%d %d\n",i,k);
				printf("%d %d\n",k,i);
			}
			else 
			{
				pa=make_pair(min(i,k),max(i,k));
				if(!st.count(pa))    //সেট এ  pa pair আছে কি না /যদি না থাকে তবে //
				{
					printf("%d %d\n",i,k);
					st.insert(pa);
				}
			}
		}
		else if(k!=pre[i])
		{
			low[i]=min(low[i],d[k]);
			pa=make_pair(min(i,k),max(i,k));
			if(!st.count(pa))    //সেট এ  pa pair আছে কি না /যদি না থাকে তবে //
			{
				printf("%d %d\n",i,k);
				st.insert(pa);
			}
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
	int n,m,u,v,Case=1;
	while(scanf("%d%d",&n,&m))
	{
		if(n==0 && m==0) break;
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
		
		cout<<Case++<<endl;
		cout<<endl;
		
		DFS(n);
		
		cout<<"#\n";
	}
	
	return 0;
}
