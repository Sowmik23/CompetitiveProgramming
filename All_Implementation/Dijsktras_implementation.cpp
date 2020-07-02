#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> > ar[100005];
int par[10005];
int dis[100005];

void printpath(int x)
{
	if(par[x]==-1) return ;
	printpath(par[x]);
	cout<<" "<<x;
}

void bfs(int x)
{
	priority_queue< pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	//priority_queue< int,vector<int> ,greater<int> > pq;
	pq.push({x,0});
	//pq.push(x);
	dis[x]=0;
	while(!pq.empty())
	{
		int u=pq.top().first;
		//int u=pq.top();
		pq.pop();
		vector< pair<int,int> >:: iterator it;
		for(it=ar[u].begin();it!=ar[u].end();it++)
		{
			int v=(*it).first;
			int weight=(*it).second;
			if(dis[v]>dis[u]+weight)
			{
				dis[v]=dis[u]+weight;
				pq.push({v,dis[v]});
				//pq.push(v);
				par[v]=u;
			}
		}
	}
}

int main()
{
	int n,m,x,y,z;
	cin>>n>>m;
	memset(dis,10000,sizeof(dis));
	while(m--)
	{
		cin>>x>>y>>z;
		ar[x].push_back({y,z});
		ar[y].push_back({x,z});
	}
	par[0]=-1;
	bfs(0);
	for(int i=1;i<n;i++)
	{
		cout<<0<<"->"<<i<<"    "<<dis[i]<<"      "<<0;
		printpath(i);
		cout<<endl;
	}
	return 0;
}

/*
input:
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7 
output:
* 0->1    4      0 1
0->2    12      0 1 2
0->3    19      0 1 2 3
0->4    21      0 7 6 5 4
0->5    11      0 7 6 5
0->6    9      0 7 6
0->7    8      0 7
0->8    14      0 1 2 8

*/

