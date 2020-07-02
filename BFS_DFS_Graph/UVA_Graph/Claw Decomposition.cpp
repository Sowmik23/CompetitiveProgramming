#include <bits/stdc++.h>
using namespace std;
vector<int>v1[1000];
int visited[1009];
int color=1;

int BFS(int x)
{
	queue<int>mq;
	mq.push(x);
	
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
			else if(visited[k]==visited[top]) return -1;
		}	
	}
	return 1;
}

int main()
{
	int n,a,b;
	while(scanf("%d",&n) && n!=0)
	{
		while(1)
		{
			scanf("%d%d",&a,&b);
			if(a==0 && b==0) break;
			v1[a].push_back(b);
			v1[b].push_back(a);
		}
		memset(visited,-1,sizeof(visited));
		
		int res;
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==-1)
			{
				res=BFS(i);
				if(res==-1) break;
			}
		}
		if(res==-1) cout<<"NO"<<endl;
		else if(res==1) cout<<"YES"<<endl;
		
		for(int i=0;i<=n;i++) v1[i].clear();			
	}
	
	return 0;
}
