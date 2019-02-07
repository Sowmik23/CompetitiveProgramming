#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v1;
int cost[10005][10005],visited[100005];
int sum;

int main()
{
	int n,m,u,v,w;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		cost[u][v]=w;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(cost[i][j]==0) cost[i][j]=1000;
		}
	}
	visited[0]=1;
	int mm,nn,a,b;
	nn=1;
	while(nn<n)
	{
		mm=1000;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(cost[i][j]<mm)
				{
					mm=cost[i][j];
					a=i;
					b=j;
				}
			}
		}
		if(visited[a]==0 || visited[b]==0)
		{
			nn++;
			v1.push_back(make_pair(a,b));
			sum+=mm;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=1000;
	}
	cout<<"Weight of MST: "<<sum<<endl;
	cout<<" MST edges are: "<<endl;
	int len=v1.size();
	for(int i=0;i<len;i++)
	{
		cout<<v1[i].first<<" "<<v1[i].second<<endl;
	}

	return 0;
}
