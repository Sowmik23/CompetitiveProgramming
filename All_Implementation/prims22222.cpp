#include<bits/stdc++.h>
using namespace std;
int cost[1000][1000];
int visited[100005];
vector< pair<int,int> >vv;
int sum;
int main()
{
	int u,v,n,m,w;
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v>>w;
		cost[u][v]=w;
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	if(cost[i][j]==0) cost[i][j]=1000;
	visited[0]=1;
	int mi,ne=1,a,b;
	while(ne<n)
	{
		mi=1000;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(cost[i][j]<mi )
				{
					mi=cost[i][j];
					a=i;
					b=j;
				}
			}
		}
		if(visited[a]==0 || visited[b]==0)
		{
			ne++;
			//cout<<a<<" "<<b<<"          "<<mi<<endl;
			vv.push_back(make_pair(a,b));
			sum+=mi;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=1000;
	}
	cout<<"weight of MST: "<<sum<<endl;
	cout<<"MST edges are: "<<endl;
	for(int i=0;i<vv.size();i++)
	{
		cout<<vv[i].first<<" "<<vv[i].second<<endl;
	}
}

