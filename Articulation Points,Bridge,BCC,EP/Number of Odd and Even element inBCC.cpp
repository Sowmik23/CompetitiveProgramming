#include <bits/stdc++.h>
using namespace std;

vector<int> v1[1005];
stack<pair<int,int> >stk;
int visited[1005],pre[1005],d[1005],low[1005],f[1005],child[1005];
int t,cnt,even=0,odd=0;

void dfs_visit(int i)
{
	visited[i]=1;
	t=t+1;
	low[i]=d[i]=t;
	child[i]=0;
	cnt=0;
	int len=v1[i].size();
	for(int j=0;j<len;j++)
	{
		int k=v1[i][j];
		if(visited[k]==0)
		{
			child[i]++;
			pre[k]=i;
			stk.push({i,k});
			
			dfs_visit(k);
			low[i]=min(low[i],low[k]);
			if((pre[i]==-1 && child[i]>1 ) || (pre[i]!=-1 && low[k]>=d[i]))
			{ 
				while(stk.top().first!=i || stk.top().second!=k)
				{
					cout<<stk.top().first<<"-->"<<stk.top().second<<" ";
					stk.pop();
					cnt++;
				}
				cout<<stk.top().first<<"-->"<<stk.top().second<<endl;
				stk.pop();
				if(cnt&1) odd++;
				else even++;
			}
		}
		else if(k!=pre[i] && d[k]<low[i])
		{
			low[i]=min(low[i],d[k]);
			stk.push({i,k});
		}
	}	
}

void DFS(int n)
{
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			cnt=0;
			dfs_visit(i);
			
			/*print the bcc */
			while(!stk.empty())
			{
				cnt++;
				cout<<stk.top().first<<"-->"<<stk.top().second<<" ";
				stk.pop();
			}
			cout<<endl;
			if(cnt!=0)
			{
				if(cnt&1) odd++;
				else even++;
			}
		}
	}
	cout<<"Odd Number: "<<odd<<" Even Number: "<<even<<endl;
}

int main()
{
	int n,m,u,v;
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v;
		v1[u].push_back(v);
		v1[v].push_back(u);
	}
	
	memset(visited,0,sizeof(visited));
	memset(pre,-1,sizeof(pre));
	
	DFS(n);
	
	
	return 0;
}

