#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,m,u,v,l=1;
	scanf("%d\n\n",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		
		int a[n];
		vector<int>v1[n];
		int visited[n];
		for(int i=0;i<n;i++) visited[i]=0;
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		while(m--)
		{
			scanf("%d%d",&u,&v);
			v1[u].push_back(v);
		}
		
		int sum=0,d;
		
		queue<int>mq;
		mq.push(0);
		visited[0]=1;
		while(!mq.empty())
		{
			int top=mq.front();
			mq.pop();
			int len=v1[top].size();
			int mx=0,p=-1;
			for(int i=0;i<len;i++)
			{
				int k=v1[top][i];
				if(!visited[k])
				{
					if(a[k]>mx)
					{
						mx=a[k];
						p=k;
					}
				}
			}
			if(p!=-1){ sum+=mx,d=p,mq.push(p);}
		}
		cout<<"Case "<<l++<<": "<<sum<<" "<<d<<endl;
		for(int i=0;i<n;i++) v1[i].clear();
	}
	
	return 0;
}
