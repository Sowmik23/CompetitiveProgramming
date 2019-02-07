#include <bits/stdc++.h>
using namespace std;
int visited[10000],color=1;

int BFS(int a,map<int,vector<int> >v1)
{
	queue<int>mq;
	mq.push(a);
	
	while(!mq.empty())
	{
		int top=mq.front();
		mq.pop();
		
		if(visited[top]==-1)
		{
			visited[top]=color;
			color=1-color;
		}
		else color=1-visited[top];
		
		int len=v1[top].size();
		for(int i=0;i<len;i++)
		{
			int k=v1[top][i];
			if(visited[k]==-1)
			{
				visited[k]=color;
				mq.push(k);
			} 
			else if(visited[k]==visited[top]) return 0;
		}
	}
	return 1;		
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,u,v;
		cin>>n>>m;
		
		memset(visited,-1,sizeof(visited));
		map<int,vector<int> >v1;
		
		while(m--)
		{
			cin>>u>>v;
			v1[u].push_back(v);
			v1[v].push_back(u);
		}
		for(int i=0;i<n;i++)
		{
			if(visited[i]==-1)
			{
				int p=BFS(i,v1);
				if(p==0) 
				{
					cout<<"Not Bipartite"<<endl;
				}
				else cout<<"Bipartite"<<endl;
			}
		}
	}

	return 0;
}

