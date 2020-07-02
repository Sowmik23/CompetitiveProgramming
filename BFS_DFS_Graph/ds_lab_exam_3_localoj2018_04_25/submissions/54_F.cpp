#include <bits/stdc++.h>
using namespace std;
vector<int>v1[100005];
int visited[100005],diameter[100005];
int n,m;

int BFS(int g)
{
	queue<int>mq;
	vector<int>::iterator it;
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
	return (max_element(diameter , diameter + n) - diameter);
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
