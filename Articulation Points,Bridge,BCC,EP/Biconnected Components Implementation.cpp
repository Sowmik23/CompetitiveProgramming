/*
12 14
0 1
1 2
1 3
2 3
2 4
3 4
1 5
0 6
5 6
5 7
5 8
7 8
8 9
10 11
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> v1[1005];
stack<pair<int,int> >stk;
vector<stack<pair<int,int> > > v2;

int visited[1005],pre[1005],d[1005],low[1005],child;
int t,cnt;

void dfs_visit(int i)
{
	visited[i]=1;
	t=t+1;
	low[i]=d[i]=t;
	child=0;
	int len=v1[i].size();
	for(int j=0;j<len;j++)
	{
		int k=v1[i][j];
		if(visited[k]==0)
		{
			child++;
			pre[k]=i;
			stk.push({i,k});
			
			dfs_visit(k);
			low[i]=min(low[i],low[k]);
			if((pre[i]==-1 && child>1 ) || (pre[i]!=-1 && low[k]>=d[i]))
			{ 
				stack<pair<int,int> >stk2;
				
				while((stk.top().first)!=i || (stk.top().second)!=k)
				{
					//cout<<stk.top().first<<".."<<stk.top().second<<" ";
					
					stk2.push({stk.top().first,stk.top().second});
					
					stk.pop();
				}
				//cout<<stk.top().first<<".."<<stk.top().second;
				
				stk2.push({stk.top().first,stk.top().second});
				
				stk.pop();
				
				v2.push_back(stk2);
				
				//cout<<endl;
				//cnt++;
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
			dfs_visit(i);
		}
		if(stk.size()>0) v2.push_back(stk);
		while(!stk.empty()) stk.pop();
		/*int p=0;
		while(!stk.empty())
		{
			p=1;
			cout<<stk.top().first<<".."<<stk.top().second<<" ";
			stk.pop();
		}
		if(p==1)
		{
			cnt++;
			cout<<endl;
		}	*/
	}
	//cout<<cnt<<endl;
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
		
	int ll=v2.size();
	cout<<"Number of BCC: "<<ll<<endl;
	for(int i=0;i<ll;i++)
	{
		while(!v2[i].empty())
		{
			cout<<v2[i].top().first<<"-->"<<v2[i].top().second<<" ";
			v2[i].pop();
		}
		cout<<endl;
	}
		
	return 0;
}

