#include <bits/stdc++.h>
using namespace std;
int visited[10000],color=1;

int BFS(int a,map<int,vector<int> >v1)
{
	queue<int>mq;
	mq.push(a);
	int d1,d2;
	d1=0;
	d2=0;
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
		d1++;   //how many place we have gone;
		if(visited[top]==1) d2++; //new visited place;
		int len=v1[top].size();
		for(int i=0;i<len;i++)
		{
			int k=v1[top][i];
			if(visited[k]==-1)
			{
				visited[k]=color;
				mq.push(k);
			} 
			else if(visited[k]==visited[top]) return -1;
		}
	}
	if(d1==1) return 1;
	return min(d2,(d1-d2));		
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
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(visited[i]==-1)
			{
				int p=BFS(i,v1);
				if(p==-1) 
				{
					ans=-1;
					break;
				}
				else ans+=p;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
