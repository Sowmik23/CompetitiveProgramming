#include <bits/stdc++.h>
using namespace std;

int n,j=0;
vector<int>v1[1000];
int visited[100000],ans[10000];

void bfs(int x)
{
	queue<int>mq;
	mq.push(x);
	//ans[j++]=x;
	while(!mq.empty())
	{
		int top = mq.front();
		mq.pop();
		//visited[top]=1;
		int l = v1[top].size();
		for(int k=0;k<l;k++)
		{
			int m = v1[top][k];
			if(visited[m]==0)
			{
				visited[m]=1;
				
				//mq.push(m);
			}
		}
	}
}

int main()
{
	int x;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		while(scanf("%d",&x))
		{
			if(x==0) break;
			v1[i].push_back(x);
		}
	}
	
	memset(visited,0,sizeof(visited));
	
	
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			ans[j++]=i;
			bfs(i);
		}
	}
	
	printf("%d\n",j);
	for(int i=0;i<j;i++)
	{
		if(i) printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	for(int i=0;i<=n;i++)
	{
		v1[i].clear();
	}

	return 0;
}
