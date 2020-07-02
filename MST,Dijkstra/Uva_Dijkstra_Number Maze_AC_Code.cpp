#include <bits/stdc++.h>
using namespace std;


int arr[1009][1009],dis[1009][1009];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;

struct graph
{
	int r,c,cos;
	bool operator > (graph x)const
	{
		return x.cos<cos;
	}
}stt,st2;

void bfs()
{
	priority_queue< graph, vector<graph>, greater<graph> >pq;
	stt.r=0;
	stt.c=0;
	stt.cos=arr[0][0];
	dis[0][0]=arr[0][0];
	pq.push(stt);
	while(!pq.empty())
	{
		st2=pq.top();
		pq.pop();
		int u1=st2.r;
		int u2=st2.c;
		for(int i=0;i<4;i++)
		{
			int v1=u1+dx[i];
			int v2=u2+dy[i];
			if(v1<0 || v1>=n || v2<0 || v2>=m) continue;
			if(dis[v1][v2]>dis[u1][u2]+arr[v1][v2])
			{
				dis[v1][v2]=dis[u1][u2]+arr[v1][v2];
				stt.r=v1;
				stt.c=v2;
				stt.cos=dis[v1][v2];
				pq.push(stt);
			}
		}
	}
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&arr[i][j]);
				dis[i][j]=99999;
			}
		}
		
		bfs();
		cout<<dis[n-1][m-1]<<endl;
	}
	
	return 0;
}
