#include<bits/stdc++.h>
using namespace std;
vector<int>v1[10000];
int color=0,visited[10000];

int BFS()
{
	queue<int>mq;
	mq.push(0);
	//visited[0]=color;
	while(!mq.empty())
	{
		int top=mq.front();
		mq.pop();
		if(visited[top]==-1)
		{
			visited[top]=color;
			color=1-color;
		}
		else  color=1-visited[top];
		
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
	int n,m,x,y;
	scanf("%d%d",&n,&m);

	while(m--)
	{
		scanf("%d%d",&x,&y);
		v1[x].push_back(y);
		v1[y].push_back(x);
	}
	memset(visited,-1,sizeof(visited));
	
	if(BFS()) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	return 0;
}
