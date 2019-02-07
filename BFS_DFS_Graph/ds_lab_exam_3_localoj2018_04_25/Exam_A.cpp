#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	int visited[n],cnt[n];
	memset(visited,0,sizeof(visited));
	memset(cnt,0,sizeof(cnt));
	vector<int> v1[n];
	while(m--)
	{
		scanf("%d%d",&x,&y);
		v1[x].push_back(y);
	}
	
	queue<int>mq;
	mq.push(0);
	visited[0]=1;
	while(!mq.empty())
	{
		int top= mq.front();
		mq.pop();
		int len=v1[top].size();
		for(int i=0;i<len;i++)
		{
			int k=v1[top][i];
			if(visited[k]==0)
			{
				visited[k]=1;
				mq.push(k);
				cnt[k]=cnt[top]+1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0) cout<<i<<": Not Reachable"<<endl;
		else cout<<i<<": "<<cnt[i]<<endl;
	}
	
	
	return 0;
}
