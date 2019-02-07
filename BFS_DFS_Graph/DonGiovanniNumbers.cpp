#include <bits/stdc++.h>
using namespace std;
vector<int>v1[100000];
int visited[100000];

int main()
{
	int t,p,d,u,v;
	scanf("%d",&t);
	while(t--)
	{
		cin>>p>>d;
		
		for(int i=0;i<p;i++)
		{
			visited[p]=0;
		}
	
		while(d--)
		{
			cin>>u>>v;
			v1[u].push_back(v);
			v1[v].push_back(u);
		}

		queue<int>mq;
		mq.push(0);
		visited[0]=0;
		while(!mq.empty())
		{
			int top= mq.front();
			mq.pop();
			int len =v1[top].size();
			for(int i=0;i<len;i++)
			{
				int k=v1[top][i];
				if(visited[k]==0)
				{
					visited[k]=visited[top] + 1;
					mq.push(k);
				}
			}
		}
		for(int i=1;i<p;i++)
		{
			printf("%d\n",visited[i]);
		}
		if(t) cout<<endl;
		for(int i=0;i<p;i++) v1[i].clear();
	}
	
	return 0;
}
