#include <bits/stdc++.h>
using namespace std;
int visited[100000];

int main()
{
	int n,m,x,y;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		scanf("%d",&m);
		vector<int>v1[m+1];
		bool p=true;
		
		while(m--)
		{
			scanf("%d%d",&x,&y);
			v1[x].push_back(y);
			v1[y].push_back(x);
		}
		queue<int>mq;
		memset(visited,-1,sizeof(visited));
		mq.push(0);
		visited[0]=0;
		
		while(!mq.empty())
		{
			int top = mq.front();
			mq.pop();
			int len  =v1[top].size();
			for(int i=0;i<len;i++)
			{
				if(visited[v1[top][i]]==-1) 
				{
					if(visited[top]==0) visited[v1[top][i]]=1;
					else visited[v1[top][i]]=0;
					mq.push(v1[top][i]);
				}
				else if(visited[v1[top][i]]==visited[top]) 
				{
					p=false;
					break;
				}
			}
			if(p==false) break;
		}
		if(p==true) cout<<"BICOLORABLE.\n";
		else cout<<"NOT BICOLORABLE.\n";
	
		for(int i=0;i<n;i++)
		{
			v1[i].clear();
			mq=queue<int>();
		}
	}
	return 0;
}
