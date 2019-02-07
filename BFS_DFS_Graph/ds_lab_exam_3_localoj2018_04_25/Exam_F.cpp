#include <bits/stdc++.h>
using namespace std;
vector<int>v1[10000];
int visited[10000],diameter[10000];
int n,m;

int BFS(int g)
{
	queue<int>mq;
	memset(visited,0,sizeof(visited));
	memset(diameter,0,sizeof(diameter));
	mq.push(g);
	visited[g]=1;
	while(!mq.empty())
	{
		int top = mq.front();
		mq.pop();
		int len=v1[top].size();
		for(int i=0;i<len;i++)
		{
			int k=v1[top][i];
			if(visited[k]==0)
			{
				visited[k]=1;
				diameter[k]+=diameter[top]+1;
				mq.push(k);
			}
		}
	}
	return int(max_element(diameter + 1,diameter+n+1)-diameter);
}

int main()
{
	int x,y;
	scanf("%d",&n);
	m=n-1;
	while(m--)
	{
		scanf("%d%d",&x,&y);
		v1[x].push_back(y);
		v1[y].push_back(x);
	}
	int d=BFS(0);
	int value=BFS(d);
	cout<<diameter[value]<<endl;
	
	return 0;
}
