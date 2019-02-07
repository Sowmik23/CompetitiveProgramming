#include <bits/stdc++.h>
using namespace std;
int dp[3000],visited[3000],cnt[3000];
vector<int> v1[3000];

void BFS(int x)
{
	queue<int>mq;
	mq.push(x);
	visited[x]=1;
	while(!mq.empty())
	{
		int top=mq.front();
		mq.pop();
		int len=v1[top].size();
		for(int i=0;i<len;i++)
		{
			int k=v1[top][i];
			if(visited[k]==0)
			{
				visited[k]=1;
				mq.push(k);
				dp[k]=dp[top]+1;
				cnt[dp[k]]++;
			}
		}
	}	
}
	
int main()
{
	int e,d,t,x,p;
	cin>>e;
	for(int i=0;i<=e;i++) v1[i].clear();
	for(int i=0;i<e;i++)
	{
		scanf("%d",&d);
		
		while(d--)
		{
			scanf("%d",&p);
			v1[i].push_back(p);
		}
	}
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		
		memset(dp,0,sizeof(dp));
		memset(visited,0,sizeof(visited));
		memset(cnt,0,sizeof(cnt));

		BFS(x);
		
		int mx=0,y;
		
		for(int i=0;i<=e;i++)
		{
			if(cnt[i]>mx) 
			{
				mx=cnt[i];
				y=i;
			}
		}
		if(mx) cout<<mx<<" "<<y<<endl;
		else cout<<"0"<<endl;
		
	}

	return 0;
}
