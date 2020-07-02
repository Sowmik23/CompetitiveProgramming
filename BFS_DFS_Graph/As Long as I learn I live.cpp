#include <bits/stdc++.h>
using namespace std;
vector<int>v1[10000];
int visited[10000];

int main()
{
	int t,x,y,c=1;
	scanf("%d\n\n",&t);
	int n,m;
	while(t--)
	{
		cin>>n>>m;
		int a[n];
		for(int i=0;i<n;i++) v1[i].clear();
		memset(visited,0,sizeof(visited));
		for(int i=0;i<n;i++) cin>>a[i];
		while(m--)
		{
			cin>>x>>y;
			v1[x].push_back(y);
		}
		
		int sum=0,d;
		queue<int>mq;
		mq.push(0);
		visited[0]=1;
		while(!mq.empty())
		{
			int top=mq.front();
			mq.pop();
			int mx=-1,p=0;
			int len=v1[top].size();
			for(int i=0;i<len;i++)
			{
				int k=v1[top][i];
				
				if(visited[k]==0)
				{
					if(a[k]>mx)
					{
						mx=a[k];
						p=k;
					}
				}
			}
			if(p!=0)
			{
				sum+=mx;
				d=p;
				mq.push(p);
			}
		}
		cout<<"Case "<<c++<<": "<<sum<<" "<<d<<endl;
	}
	
	return 0;
}
